#ifndef SORTEDDATAVIEWER_H
#define SORTEDDATAVIEWER_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QBrush>
#include <QLabel>

class SortedDataViewer : public QMainWindow {
    Q_OBJECT

public:
    explicit SortedDataViewer(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Отсортированные данные");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* layout = new QVBoxLayout(centralWidget);

        // Инициализация таблицы
        tableWidget = new QTableWidget(this);
        tableWidget->setColumnCount(6); // Добавляем ещё одну колонку для индекса
        tableWidget->setHorizontalHeaderLabels({"#", "Имя", "Фамилия", "Год рождения", "Рост", "Вес"});
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Отключение автоматического индексирования слева
        tableWidget->verticalHeader()->setVisible(false);

        layout->addWidget(tableWidget);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }

    void setData(const QVector<QVector<QString>>& data, int sortColumnIndex = -1) {
        tableWidget->setRowCount(data.size() + 1); // Увеличить количество строк на 1 для заголовков

        const QStringList headers = {"", "Имя", "Фамилия", "Год рождения", "Рост", "Вес"};
        for (int j = 0; j < headers.size(); ++j) {
            auto* headerItem = new QTableWidgetItem(headers[j]);
            headerItem->setFlags(Qt::ItemIsEnabled); // Заголовок нельзя редактировать
            headerItem->setFont(QFont("Arial", 10, QFont::Bold)); // Жирный шрифт
            headerItem->setTextAlignment(Qt::AlignCenter);
            if (j == sortColumnIndex + 1) { // Смещаем индекс для корректного подсвечивания
                headerItem->setBackground(QBrush(Qt::darkMagenta));
                headerItem->setForeground(QBrush(Qt::white));
            }
            tableWidget->setItem(0, j, headerItem); // Добавление заголовков
        }

        // Заполнение данных и индексов
        for (int i = 0; i < data.size(); ++i) {
            // Установка индекса
            auto* indexItem = new QTableWidgetItem(QString::number(i + 1)); // Индексация со 2
            indexItem->setFlags(Qt::ItemIsEnabled); // Индекс нельзя редактировать
            indexItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i + 1, 0, indexItem); // Первый столбец для индексов

            // Установка данных
            for (int j = 0; j < data[i].size(); ++j) {
                auto* item = new QTableWidgetItem(data[i][j]);
                if (j == sortColumnIndex) {
                    item->setBackground(QBrush(Qt::darkMagenta));
                    item->setForeground(QBrush(Qt::white));
                }
                tableWidget->setItem(i + 1, j + 1, item); // Смещение на одну колонку вправо
            }
        }
    }

private:
    QTableWidget* tableWidget;
};

#endif // SORTEDDATAVIEWER_H
