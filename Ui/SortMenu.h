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
#include <QMessageBox>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <fstream>
#include "../PersonComparators.h"
#include "../quickSort.h"
#include "../binaryInsertionSort.h"
#include "../mergeSort.h"
#include "../ArraySequence.h"
#include "SortedDataViewer.h"
#include "SortingVisualizer.h"

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
        sortParameterComboBox->addItems({"Возраст", "Рост", "Вес"});
        sortParameterLayout->addWidget(sortParameterComboBox);
        layout->addLayout(sortParameterLayout);

        auto* sortOrderLayout = new QVBoxLayout();
        sortOrderLayout->addWidget(new QLabel("Порядок сортировки:", this));
        sortOrderComboBox = new QComboBox(this);
        sortOrderComboBox->addItems({"По возрастанию", "По убыванию"});
        sortOrderLayout->addWidget(sortOrderComboBox);
        layout->addLayout(sortOrderLayout);

        auto* sortModeLayout = new QVBoxLayout();
        sortModeLayout->addWidget(new QLabel("Режим работы:", this));
        sortModeComboBox = new QComboBox(this);
        sortModeComboBox->addItems({"С визуализацией", "Без визуализации"});
        sortModeLayout->addWidget(sortModeComboBox);
        layout->addLayout(sortModeLayout);

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
        QString sortMode = sortModeComboBox->currentText();
        QString inputFilePath = filePathLineEdit->text();

        progressBar->setValue(0);
        if (inputFilePath.isEmpty()) {
            resultLabel->setText("Ошибка: файл не выбран.");
            return;
        }

        if (sortMode == "С визуализацией") {
            startSortingWithVisualization(sortType, sortParameter, sortOrder, inputFilePath);
        } else {
            startSortingWithoutVisualization(sortType, sortParameter, sortOrder, inputFilePath);
        }
    }
    void startSortingWithoutVisualization(const QString& sortType, const QString& sortParameter, const QString& sortOrder, const QString& inputFilePath) {
        statusLabel->setText("Сортировка без визуализации...");

            statusLabel->setText("Чтение файла...");
            QCoreApplication::processEvents();
            QElapsedTimer timer;
            timer.start();

            ArraySequence<Person> persons;
            std::ifstream inputFile(inputFilePath.toStdString());
            if (!inputFile.is_open()) {
                resultLabel->setText("Ошибка: Не удалось открыть файл.");
                return;
            }

            std::string line;
            std::getline(inputFile, line);
            while (std::getline(inputFile, line)) {
                std::istringstream stream(line);
                std::string firstName, lastName, birthYear, height, weight;

                std::getline(stream, firstName, ',');
                std::getline(stream, lastName, ',');
                std::getline(stream, birthYear, ',');
                std::getline(stream, height, ',');
                std::getline(stream, weight, ',');

                persons.Append(Person(firstName, lastName, std::stoi(birthYear), std::stod(height), std::stod(weight)));
            }
            inputFile.close();
            progressBar->setValue(1);

            statusLabel->setText("Сортировка...");
            QCoreApplication::processEvents();

            int (*comparator)(const Person&, const Person&) = getComparator(sortParameter, sortOrder);

            if (sortType == "Быстрая") {
                QuickSorter<Person> sorter;
                sorter.Sort(persons, comparator);
            } else if (sortType == "Бинарная вставка") {
                BinaryInsertionSorter<Person> sorter;
                sorter.Sort(persons, comparator);
            } else if (sortType == "Слиянием") {
                MergeSorter<Person> sorter;
                sorter.Sort(persons, comparator);
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

            outputFile << "Имя,Фамилия,Год рождения,Рост,Вес\n";
            for (size_t i = 0; i < persons.GetLength(); ++i) {
                const Person& p = persons[i];
                outputFile << p.getFirstName() << "," << p.getLastName() << "," << (2024 - p.getAge()) << "," << p.getHeight()
                << "," << p.getWeight() << "\n";
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
                sortColumnIndex = 2; // Год рождения
            } else if (sortParameter == "Рост") {
                sortColumnIndex = 3; // Рост
            } else if (sortParameter == "Вес") {
                sortColumnIndex = 4; // Вес
            }

            // Сбор данных для отображения в новом окне
            QVector<QVector<QString>> sortedData;
            for (size_t i = 0; i < persons.GetLength(); ++i) {
                const Person& p = persons[i];
                sortedData.append({
                    QString::fromStdString(p.getFirstName()),
                    QString::fromStdString(p.getLastName()),
                    QString::number(2024 - p.getAge()),
                    QString::number(p.getHeight(), 'f', 2),
                    QString::number(p.getWeight(), 'f', 2)
                });
            }

            // Создаём и показываем новое окно
            auto* viewer = new SortedDataViewer(this);

            QRect mainWindowGeometry = this->frameGeometry();
            int x = mainWindowGeometry.right(); // Правая сторона главного окна
            int y = mainWindowGeometry.top();   // Верхняя граница главного окна

            // Устанавливаем размер окна с результатами: ширина в 2 раза меньше, высота такая же
            int newWidth = mainWindowGeometry.width() / 2;
            int newHeight = mainWindowGeometry.height();
            viewer->resize(newWidth, newHeight); // Изменяем размер окна

            viewer->move(x, y);  // Перемещаем окно с результатами в нужное место

            viewer->setData(sortedData, sortColumnIndex); // Передаём данные и индекс столбца
            viewer->show();

    }
    void startSortingWithVisualization(const QString& sortType, const QString& sortParameter, const QString& sortOrder, const QString& inputFilePath) {
        statusLabel->setText("Запуск визуализации сортировки...");

        // Создаем окно визуализации сортировки
        auto* visualizer = new SortingVisualizer(sortType, sortParameter, sortOrder, inputFilePath, this);
        visualizer->show();
    }


private:
    static int (*getComparator(const QString& sortParameter, const QString& sortOrder))(const Person&, const Person&) {
        if (sortParameter == "Возраст") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByAge : DescendingComparatorByAge;
        }
        if (sortParameter == "Рост") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByHeight : DescendingComparatorByHeight;
        }
        if (sortParameter == "Вес") {
            return sortOrder == "По возрастанию" ? AscendingComparatorByWeight : DescendingComparatorByWeight;
        }
        throw std::invalid_argument("Неверный параметр сортировки");
    }

    QComboBox *sortTypeComboBox;
    QComboBox *sortParameterComboBox;
    QComboBox *sortOrderComboBox;
    QLineEdit *filePathLineEdit;
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QLabel *resultLabel;
    QComboBox* sortModeComboBox;
};

#endif // SORTMENU_H
