#ifndef SORTINGVISUALIZER_H
#define SORTINGVISUALIZER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <vector>
#include <functional>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

// Подключаем существующие реализации сортировок
#include "../quickSort.h"
#include "../mergeSort.h"
#include "../binaryInsertionSort.h"

class SortingVisualizer : public QWidget {
    Q_OBJECT

private:
    std::vector<int> data;                // Данные для сортировки
    QGraphicsView* view;                  // Графическое представление
    QGraphicsScene* scene;                // Сцена для рисования
    QTimer* timer;                        // Таймер для анимации
    int currentStep;                      // Текущий шаг
    std::vector<std::vector<int>> steps; // Шаги сортировки

public:
    SortingVisualizer(const QString& sortType, const QString& sortParameter,
                      const QString& sortOrder, const QString& inputFilePath,
                      QWidget* parent = nullptr)
        : QWidget(parent), view(new QGraphicsView(this)),
          scene(new QGraphicsScene(this)), timer(new QTimer(this)),
          currentStep(0) {
        view->setScene(scene);
        view->setFixedSize(600, 400);
        connect(timer, &QTimer::timeout, this, &SortingVisualizer::visualizeStep);

        // Загружаем данные из файла
        if (!loadDataFromFile(inputFilePath)) {
            QMessageBox::critical(this, "Ошибка", "Не удалось загрузить данные из файла!");
            return;
        }

        // Определяем алгоритм сортировки
        Algorithm algorithm = determineAlgorithm(sortType);

        // Настраиваем порядок сортировки
        if (sortOrder.toLower() == "descending") {
            for (int& value : data) {
                value = -value; // Инвертируем для имитации сортировки по убыванию
            }
        }

        // Запускаем визуализацию сортировки
        startVisualization(algorithm);
    }

    ~SortingVisualizer() {
        delete timer;
        delete view;
        delete scene;
    }

private:
    enum class Algorithm { QuickSort, MergeSort, BinaryInsertionSort };

    void startVisualization(Algorithm algorithm) {
        if (data.empty()) return;

        executeSort(algorithm);
        currentStep = 0;
        timer->start(500);
    }

    void visualizeStep() {
        if (currentStep >= steps.size()) {
            timer->stop();
            return;
        }

        data = steps[currentStep];
        drawArray();
        ++currentStep;
    }

    void drawArray() {
        scene->clear();

        int rectWidth = 20;
        int spacing = 5;

        for (size_t i = 0; i < data.size(); ++i) {
            int value = data[i];
            int rectHeight = abs(value) * 3; // Возвращаем абсолютное значение

            QGraphicsRectItem* rect = new QGraphicsRectItem(
                i * (rectWidth + spacing), 300 - rectHeight,
                rectWidth, rectHeight
            );

            rect->setBrush(QBrush(Qt::blue));
            rect->setPen(QPen(Qt::black));
            scene->addItem(rect);
        }
    }

    void executeSort(Algorithm algorithm) {
        // Создаём ArraySequence из вектора данных
        ArraySequence<int> sequence(data.data(), static_cast<int>(data.size()));

        // Указатель на общий интерфейс сортировщика
        std::unique_ptr<ISorter<int>> sorter;

        // Выбор сортировщика в зависимости от алгоритма
        switch (algorithm) {
            case Algorithm::QuickSort:
                sorter = std::make_unique<QuickSorter<int>>();
            break;
            case Algorithm::MergeSort:
                sorter = std::make_unique<MergeSorter<int>>();
            break;
            case Algorithm::BinaryInsertionSort:
                sorter = std::make_unique<BinaryInsertionSorter<int>>();
            break;
            default:
                throw std::invalid_argument("Unknown sorting algorithm");
        }

        // Выполнение сортировки
        if (sorter) {
            sorter->Sort(sequence, [](const int& a, const int& b) {
                return a - b; // Сравнение для сортировки по возрастанию
            });
        }

        // Копируем отсортированные данные обратно в вектор
        data.clear();
        for (int i = 0; i < sequence.GetLength(); ++i) {
            data.push_back(sequence[i]);
        }
    }



    Algorithm determineAlgorithm(const QString& sortType) {
        if (sortType.toLower() == "quicksort") {
            return Algorithm::QuickSort;
        } else if (sortType.toLower() == "mergesort") {
            return Algorithm::MergeSort;
        } else if (sortType.toLower() == "binaryinsertionsort") {
            return Algorithm::BinaryInsertionSort;
        } else {
            QMessageBox::critical(this, "Ошибка", "Неизвестный алгоритм сортировки!");
            return Algorithm::QuickSort; // По умолчанию
        }
    }

    bool loadDataFromFile(const QString& inputFilePath) {
        QFile file(inputFilePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return false;
        }

        QTextStream in(&file);
        data.clear();

        while (!in.atEnd()) {
            QString line = in.readLine();
            bool ok;
            int value = line.toInt(&ok);
            if (ok) {
                data.push_back(value);
            }
        }

        file.close();
        return !data.empty();
    }
};

#endif // SORTINGVISUALIZER_H
