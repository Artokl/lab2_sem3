#ifndef SORTEDDATAVIEWER_H
#define SORTEDDATAVIEWER_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QBrush>
#include <QLabel>

class SortedDataViewer final : public QMainWindow {
    Q_OBJECT

public:
    explicit SortedDataViewer(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Отсортированные данные");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* layout = new QVBoxLayout(centralWidget);

        tableWidget = new QTableWidget(this);
        tableWidget->setColumnCount(6);
        tableWidget->setHorizontalHeaderLabels({"", "Имя", "Фамилия", "Год рождения", "Рост", "Вес"});
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        tableWidget->verticalHeader()->setVisible(false);

        layout->addWidget(tableWidget);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }

    void setData(const QVector<QVector<QString>>& data, const int sortColumnIndex = -1) const {
        tableWidget->setRowCount(data.size() + 1);

        const QStringList headers = {"", "Имя", "Фамилия", "Год рождения", "Рост", "Вес"};
        for (int j = 0; j < headers.size(); ++j) {
            auto* headerItem = new QTableWidgetItem(headers[j]);
            headerItem->setFlags(Qt::ItemIsEnabled);
            headerItem->setFont(QFont("Arial", 10, QFont::Bold));
            headerItem->setTextAlignment(Qt::AlignCenter);
            if (j == sortColumnIndex + 1) {
                headerItem->setBackground(QBrush(Qt::darkMagenta));
                headerItem->setForeground(QBrush(Qt::white));
            }
            tableWidget->setItem(0, j, headerItem);
        }

        for (int i = 0; i < data.size(); ++i) {
            auto* indexItem = new QTableWidgetItem(QString::number(i + 1));
            indexItem->setFlags(Qt::ItemIsEnabled);
            indexItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i + 1, 0, indexItem);


            for (int j = 0; j < data[i].size(); ++j) {
                auto* item = new QTableWidgetItem(data[i][j]);
                if (j == sortColumnIndex) {
                    item->setBackground(QBrush(Qt::darkMagenta));
                    item->setForeground(QBrush(Qt::white));
                }
                tableWidget->setItem(i + 1, j + 1, item);
            }
        }
    }

private:
    QTableWidget* tableWidget;
};

#endif // SORTEDDATAVIEWER_H
