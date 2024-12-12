#ifndef SORTMENU_H
#define SORTMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QFileDialog>
#include <QProgressBar>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QApplication>
#include <fstream>

#include "SortedDataViewer.h"
#include "../ResumeComparators.h"
#include "../QuickSort.h"
#include "../BinaryInsertionSort.h"
#include "../MergeSort.h"
#include "../ArraySequence.h"

class SortMenu final : public QMainWindow {
    Q_OBJECT
public:
    explicit SortMenu(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Меню сортировки");
        resize(900, 600);

        auto* centralWidget = new QWidget(this);
        auto* layout = new QVBoxLayout(centralWidget);
        auto* sortTypeLayout = new QHBoxLayout();

        auto* sortTypeLabel = new QLabel("Тип сортировки:", this);
        sortTypeComboBox = new QComboBox(this);
        sortTypeComboBox->addItems({"Быстрая", "Бинарная вставка", "Слиянием"});

        sortTypeLayout->addWidget(sortTypeLabel);
        sortTypeLayout->addWidget(sortTypeComboBox);
        layout->addLayout(sortTypeLayout);

        auto* sortParameterLayout = new QVBoxLayout();
        sortParameterLayout->addWidget(new QLabel("Параметр сортировки:", this));
        sortParameterComboBox = new QComboBox(this);
        sortParameterComboBox->addItems({"Возраст", "Рост", "Вес", "Зарплата", "Опыт работы", "Количество сертификатов"});
        sortParameterLayout->addWidget(sortParameterComboBox);
        layout->addLayout(sortParameterLayout);

        auto* sortOrderLayout = new QVBoxLayout();
        sortOrderLayout->addWidget(new QLabel("Порядок сортировки:", this));
        sortOrderComboBox = new QComboBox(this);
        sortOrderComboBox->addItems({"По возрастанию", "По убыванию"});
        sortOrderLayout->addWidget(sortOrderComboBox);
        layout->addLayout(sortOrderLayout);

        auto* separator = new QFrame(this);
        separator->setFrameShape(QFrame::HLine);
        separator->setFrameShadow(QFrame::Sunken);
        layout->addWidget(separator);

        auto* fileLayout = new QHBoxLayout();
        fileLayout->addWidget(new QLabel("Файл CSV:", this));
        filePathLineEdit = new QLineEdit(this);
        filePathLineEdit->setReadOnly(true);

        auto* selectFileButton = new QPushButton("Выбрать", this);
        fileLayout->addWidget(filePathLineEdit);
        fileLayout->addWidget(selectFileButton);
        layout->addLayout(fileLayout);
        connect(selectFileButton, &QPushButton::clicked, this, &SortMenu::selectFile);

        auto* startButton = new QPushButton("Начать сортировку", this);
        layout->addWidget(startButton);
        connect(startButton, &QPushButton::clicked, this, &SortMenu::startSorting);

        progressBar = new QProgressBar(this);
        progressBar->setRange(0, 3);
        progressBar->setValue(0);
        layout->addWidget(progressBar);

        statusLabel = new QLabel("Ожидание пользователя...", this);
        statusLabel->setWordWrap(true);
        layout->addWidget(statusLabel);

        resultLabel = new QLabel("Результат будет отображён здесь.", this);
        resultLabel->setWordWrap(true);
        layout->addWidget(resultLabel);

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }
private slots:
    void selectFile() {
        if (const QString filePath = QFileDialog::getOpenFileName(
            this, "Выберите CSV файл", "", "CSV файлы (*.csv)"); !filePath.isEmpty()) {
            filePathLineEdit->setText(filePath);
        }
    }
    void startSorting() {
        QString sortType = sortTypeComboBox->currentText();
        QString sortParameter = sortParameterComboBox->currentText();
        QString sortOrder = sortOrderComboBox->currentText();
        QString inputFilePath = filePathLineEdit->text();
        progressBar->setValue(0);
        if (inputFilePath.isEmpty()) {
            resultLabel->setText("Ошибка: файл не выбран.");
            return;
        }

        statusLabel->setText("Чтение файла...");
        QCoreApplication::processEvents();
        QElapsedTimer timer;
        timer.start();

        ArraySequence<Resume> resumes;
        std::ifstream inputFile(inputFilePath.toStdString());
        if (!inputFile.is_open()) {
            resultLabel->setText("Ошибка: Не удалось открыть файл.");
            return;
        }
        std::string line;
        std::getline(inputFile, line);  // Skip header line
        while (std::getline(inputFile, line)) {
            std::istringstream stream(line);
            std::string firstName, lastName, birthYear, height, weight, desiredPosition, skills, education, desiredSalary, yearsOfExperience, certificationsCount;
            std::getline(stream, firstName, ',');
            std::getline(stream, lastName, ',');
            std::getline(stream, birthYear, ',');
            std::getline(stream, height, ',');
            std::getline(stream, weight, ',');
            std::getline(stream, desiredPosition, ',');
            std::getline(stream, skills, ',');
            std::getline(stream, education, ',');
            std::getline(stream, desiredSalary, ',');
            std::getline(stream, yearsOfExperience, ',');
            std::getline(stream, certificationsCount, ',');
            resumes.Append(Resume(firstName, lastName, std::stoi(birthYear), std::stod(height), std::stod(weight),
                                  desiredPosition, skills, education, std::stod(desiredSalary), std::stod(yearsOfExperience), std::stod(certificationsCount)));
        }
        inputFile.close();

        progressBar->setValue(1);
        statusLabel->setText("Сортировка...");
        QCoreApplication::processEvents();

        int (*comparator)(const Resume&, const Resume&) = getComparator(sortParameter, sortOrder);
        if (sortType == "Быстрая") {
            QuickSorter<Resume> sorter;
            sorter.Sort(resumes, comparator);
        } else if (sortType == "Бинарная вставка") {
            BinaryInsertionSorter<Resume> sorter;
            sorter.Sort(resumes, comparator);
        } else if (sortType == "Слиянием") {
            MergeSorter<Resume> sorter;
            sorter.Sort(resumes, comparator);
        } else {
            resultLabel->setText("Ошибка: Неверный тип сортировки.");
            return;
        }

        progressBar->setValue(2);
        statusLabel->setText("Запись в файл...");
        QCoreApplication::processEvents();

        QString outputFilePath = "output.csv";
        std::ofstream outputFile(outputFilePath.toStdString());
        if (!outputFile.is_open()) {
            resultLabel->setText("Ошибка: Не удалось сохранить файл.");
            return;
        }

        outputFile << "Имя,Фамилия,Год рождения,Рост,Вес,Желаемая позиция,Навыки,Образование,Желаемая зарплата,Опыт работы,Количество сертификатов\n";
        for (size_t i = 0; i < resumes.GetLength(); ++i) {
            const Resume& r = resumes[i];
            outputFile << r.getFirstName() << "," << r.getLastName() << "," << (2024 - r.getAge()) << "," << r.getHeight()
            << "," << r.getWeight() << "," << r.getDesiredPosition() << "," << r.getSkills() << "," << r.getEducation()
            << "," << r.getDesiredSalary() << "," << r.getYearsOfExperience() << "," << r.getCertificationsCount() << "\n";
        }
        outputFile.close();

        progressBar->setValue(3);
        statusLabel->setText("Данные успешно записаны в файл.");
        QCoreApplication::processEvents();

        double elapsedTime = timer.elapsed() / 1000.0;
        resultLabel->setText(QString("Сортировка завершена.\n"
                                    "Исходный файл: %1\n"
                                    "Сохранено в: %2\n"
                                    "Время выполнения: %3 секунд.")
                                .arg(inputFilePath, outputFilePath)
                                .arg(QString::number(elapsedTime, 'f', 2)));

        int sortColumnIndex = -1;
        if (sortParameter == "Возраст") {
            sortColumnIndex = 2;
        } else if (sortParameter == "Рост") {
            sortColumnIndex = 3;
        } else if (sortParameter == "Вес") {
            sortColumnIndex = 4;
        } else if (sortParameter == "Зарплата") {
            sortColumnIndex = 8;
        } else if (sortParameter == "Опыт работы") {
            sortColumnIndex = 9;
        } else if (sortParameter == "Количество сертификатов") {
            sortColumnIndex = 10;
        }

        QVector<QVector<QString>> sortedData;
        for (size_t i = 0; i < resumes.GetLength(); ++i) {
            const Resume& p = resumes[i];
            sortedData.append({
                QString::fromStdString(p.getFirstName()),
                QString::fromStdString(p.getLastName()),
                QString::number(2024 - p.getAge()),
                QString::number(p.getHeight(), 'f', 2),
                QString::number(p.getWeight(), 'f', 2),
                QString::fromStdString(p.getDesiredPosition()),
                QString::fromStdString(p.getSkills()),
                QString::fromStdString(p.getEducation()),
                QString::number(p.getDesiredSalary(), 'f', 2),
                QString::number(p.getYearsOfExperience(), 'f', 2),
                QString::number(p.getCertificationsCount())
            });
        }

        auto* viewer = new SortedDataViewer(this);
        QRect mainWindowGeometry = this->frameGeometry();
        QRect screenGeometry = QApplication::desktop()->availableGeometry(); // Get available screen geometry

        int newWidth = mainWindowGeometry.width() * 2;
        int newHeight = mainWindowGeometry.height();

        // Calculate x, ensuring it stays within screen bounds
        int x = mainWindowGeometry.left() + (mainWindowGeometry.width() - newWidth) / 2;
        x = std::max(screenGeometry.left(), std::min(x, screenGeometry.right() - newWidth));


        // Calculate y, ensuring it stays within screen bounds
        int y = mainWindowGeometry.bottom();
        y = std::min(y, screenGeometry.bottom() - newHeight);


        viewer->resize(newWidth, newHeight);
        viewer->move(x, y);
        viewer->setData(sortedData, sortColumnIndex);
        viewer->show();
    }
private:
    QComboBox* sortTypeComboBox;
    QComboBox* sortParameterComboBox;
    QComboBox* sortOrderComboBox;
    QLineEdit* filePathLineEdit;
    QProgressBar* progressBar;
    QLabel* statusLabel;
    QLabel* resultLabel;

    static int (*getComparator(const QString& sortParameter, const QString& sortOrder))(const Resume&, const Resume&) {
        if (sortParameter == "Возраст") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByAge : DescendingComparatorByAge;
        }
        if (sortParameter == "Рост") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByHeight : DescendingComparatorByHeight;
        }
        if (sortParameter == "Вес") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByWeight : DescendingComparatorByWeight;
        }
        if (sortParameter == "Зарплата") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByDesiredSalary : DescendingComparatorByDesiredSalary;
        }
        if (sortParameter == "Опыт работы") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByYearsOfExperience : DescendingComparatorByYearsOfExperience;
        }
        if (sortParameter == "Количество сертификатов") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByCertificationsCount : DescendingComparatorByCertificationsCount;
        }
        throw std::invalid_argument("Неверный параметр сортировки");
    }
};

#endif // SORTMENU_H
