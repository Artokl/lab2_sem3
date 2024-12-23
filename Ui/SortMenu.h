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
#include <QGuiApplication>
#include <QScreen>
#include <fstream>

#include "SortedDataViewer.h"
#include "../StudentComparators.h"
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
        sortParameterComboBox->addItems({"Возраст", "Рост", "Вес", "GPA", "Годы обучения", "Завершённые кредиты"});
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

        ArraySequence<Student> students;
        std::ifstream inputFile(inputFilePath.toStdString());
        if (!inputFile.is_open()) {
            resultLabel->setText("Ошибка: Не удалось открыть файл.");
            return;
        }
        std::string line;
        std::getline(inputFile, line);  // Skip header line
        while (std::getline(inputFile, line)) {
            std::istringstream stream(line);
            std::string firstName, lastName, birthYear, height, weight, universityName, faculty, major, gpa, yearsOfStudy, completedCredits;
            std::getline(stream, firstName, ',');
            std::getline(stream, lastName, ',');
            std::getline(stream, birthYear, ',');
            std::getline(stream, height, ',');
            std::getline(stream, weight, ',');
            std::getline(stream, universityName, ',');
            std::getline(stream, faculty, ',');
            std::getline(stream, major, ',');
            std::getline(stream, gpa, ',');
            std::getline(stream, yearsOfStudy, ',');
            std::getline(stream, completedCredits, ',');
            students.Append(Student(firstName, lastName, std::stoi(birthYear), std::stod(height), std::stod(weight),
                                     universityName, faculty, major, std::stod(gpa), std::stod(yearsOfStudy), std::stoi(completedCredits)));
        }
        inputFile.close();

        progressBar->setValue(1);
        statusLabel->setText("Сортировка...");
        QCoreApplication::processEvents();

        int (*comparator)(const Student&, const Student&) = getComparator(sortParameter, sortOrder);
        if (sortType == "Быстрая") {
            QuickSorter<Student> sorter;
            sorter.Sort(students, comparator);
        } else if (sortType == "Бинарная вставка") {
            BinaryInsertionSorter<Student> sorter;
            sorter.Sort(students, comparator);
        } else if (sortType == "Слиянием") {
            MergeSorter<Student> sorter;
            sorter.Sort(students, comparator);
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

        outputFile << "Имя,Фамилия,Год рождения,Рост,Вес,Университет,Факультет,Специальность,GPA,Годы обучения,Завершённые кредиты\n";
        for (size_t i = 0; i < students.GetLength(); ++i) {
            const Student& s = students[i];
            outputFile << s.getFirstName() << "," << s.getLastName() << "," << (2024 - s.getAge()) << "," << s.getHeight()
                      << "," << s.getWeight() << "," << s.getUniversityName() << "," << s.getFaculty() << "," << s.getMajor()
                      << "," << s.getGPA() << "," << s.getYearsOfStudy() << "," << s.getCompletedCredits() << "\n";
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
        } else if (sortParameter == "GPA") {
            sortColumnIndex = 8;
        } else if (sortParameter == "Годы обучения") {
            sortColumnIndex = 9;
        } else if (sortParameter == "Завершённые кредиты") {
            sortColumnIndex = 10;
        }

        QVector<QVector<QString>> sortedData;
        for (size_t i = 0; i < students.GetLength(); ++i) {
            const Student& p = students[i];
            sortedData.append({
                QString::fromStdString(p.getFirstName()),
                QString::fromStdString(p.getLastName()),
                QString::number(2024 - p.getAge()),
                QString::number(p.getHeight(), 'f', 2),
                QString::number(p.getWeight(), 'f', 2),
                QString::fromStdString(p.getUniversityName()),
                QString::fromStdString(p.getFaculty()),
                QString::fromStdString(p.getMajor()),
                QString::number(p.getGPA(), 'f', 2),
                QString::number(p.getYearsOfStudy(), 'f', 2),
                QString::number(p.getCompletedCredits())
            });
        }

        auto* viewer = new SortedDataViewer(this);
        QRect mainWindowGeometry = this->frameGeometry();

        int x = mainWindowGeometry.left() - mainWindowGeometry.width() / 2;
        int y = mainWindowGeometry.bottom();

        int newWidth = mainWindowGeometry.width() * 2;
        int newHeight = mainWindowGeometry.height();

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

    static int (*getComparator(const QString& sortParameter, const QString& sortOrder))(const Student&, const Student&) {
        if (sortParameter == "Возраст") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByAge : DescendingComparatorByAge;
        }
        if (sortParameter == "Рост") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByHeight : DescendingComparatorByHeight;
        }
        if (sortParameter == "Вес") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByWeight : DescendingComparatorByWeight;
        }
        if (sortParameter == "GPA") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByGPA : DescendingComparatorByGPA;
        }
        if (sortParameter == "Годы обучения") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByYearsOfStudy : DescendingComparatorByYearsOfStudy;
        }
        if (sortParameter == "Завершённые кредиты") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByCompletedCredits : DescendingComparatorByCompletedCredits;
        }
        return nullptr;
    }
};

#endif // SORTMENU_H











