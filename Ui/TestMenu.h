#ifndef TESTMENU_H
#define TESTMENU_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QGroupBox>
#include <QLabel>
#include <QMap>
#include <functional>

#include "../Tests/QuickSortTests.h"
#include "../Tests/MergeSortTests.h"
#include "../Tests/BinaryInsertionSortTests.h"

class TestMenu : public QMainWindow {
    Q_OBJECT

public:
    explicit TestMenu(QWidget* parent = nullptr) {
        setWindowTitle("Меню тестирования");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* mainLayout = new QVBoxLayout(centralWidget);

        auto* quickSortGroup = createTestGroup("QuickSort Тесты");
        auto* mergeSortGroup = createTestGroup("MergeSort Тесты");
        auto* binaryInsertionGroup = createTestGroup("BinaryInsertionSort Тесты");

        mainLayout->addWidget(quickSortGroup);
        mainLayout->addWidget(mergeSortGroup);
        mainLayout->addWidget(binaryInsertionGroup);
        
        auto* runTestsButton = new QPushButton("Запустить все тесты", this);
        connect(runTestsButton, &QPushButton::clicked, this, &TestMenu::runAllTests);
        mainLayout->addWidget(runTestsButton);

        progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);
        mainLayout->addWidget(progressBar);

        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        initTestGroups();
    }

private slots:
    void runAllTests() {
        progressBar->setValue(0);
        int totalTests = 0;
        int successfulTests = 0;

        for (auto it = testGroups.begin(); it != testGroups.end(); ++it) {
            QListWidget* listWidget = it.value();
            for (int i = 0; i < listWidget->count(); ++i) {
                QListWidgetItem* item = listWidget->item(i);
                auto testFunc = item->data(Qt::UserRole).value<std::function<bool()>>();
                bool success = testFunc();

                item->setText(item->text() + (success ? " - УСПЕШНО" : " - НЕУСПЕШНО"));
                item->setBackground(success ? Qt::green : Qt::red);

                if (success) ++successfulTests;
                ++totalTests;

                progressBar->setValue((totalTests * 100) / getTotalTestCount());
                QApplication::processEvents();
            }
        }

        QString result = QString("Тесты завершены: %1/%2 успешно.")
                                 .arg(successfulTests)
                                 .arg(getTotalTestCount());
        QLabel* resultLabel = new QLabel(result, this);
        static_cast<QVBoxLayout*>(centralWidget()->layout())->addWidget(resultLabel);
    }

private:
    QMap<QString, QListWidget*> testGroups; 
    QProgressBar* progressBar;             

    QGroupBox* createTestGroup(const QString& title) {
        auto* group = new QGroupBox(title, this);
        auto* layout = new QVBoxLayout(group);

        auto* listWidget = new QListWidget(this);
        layout->addWidget(listWidget);

        testGroups[title] = listWidget;
        return group;
    }

    void initTestGroups() {
        addTest("QuickSort Тесты", "Сортировка по убыванию возраста", []() {
            return QuickSortDescAgeTest("input.csv");
        });
        addTest("QuickSort Тесты", "Сортировка по возрастанию возраста", []() {
            return QuickSortAscAgeTest("input.csv");
        });
        addTest("QuickSort Тесты", "Сортировка по убыванию веса", []() {
            return QuickSortDescWeightTest("input.csv");
        });
        addTest("QuickSort Тесты", "Сортировка по возрастанию веса", []() {
            return QuickSortAscWeightTest("input.csv");
        });

        addTest("MergeSort Тесты", "Сортировка по убыванию роста", []() {
            return MergeSortDescHeightTest("input.csv");
        });
        addTest("MergeSort Тесты", "Сортировка по возрастанию роста", []() {
            return MergeSortAscHeightTest("input.csv");
        });

        addTest("BinaryInsertionSort Тесты", "Сортировка по убыванию возраста", []() {
            return BinaryInsertionSortDescAgeTest("input.csv");
        });
        addTest("BinaryInsertionSort Тесты", "Сортировка по возрастанию возраста", []() {
            return BinaryInsertionSortAscAgeTest("input.csv");
        });
    }

    void addTest(const QString& group, const QString& testName, std::function<bool()> testFunc) {
        auto* listWidget = testGroups[group];
        if (!listWidget) return;

        auto* item = new QListWidgetItem(testName, listWidget);
        QVariant testFuncVariant;
        testFuncVariant.setValue(testFunc);
        item->setData(Qt::UserRole, testFuncVariant);
    }

    int getTotalTestCount() const {
        int count = 0;
        for (auto it = testGroups.begin(); it != testGroups.end(); ++it) {
            count += it.value()->count();
        }
        return count;
    }
};

Q_DECLARE_METATYPE(std::function<bool()>)

#endif // TESTMENU_H
