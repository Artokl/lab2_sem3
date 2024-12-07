#ifndef TESTMENU_H
#define TESTMENU_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QComboBox>
#include <QProgressBar>
#include <QGroupBox>
#include <QLabel>
#include <QMap>
#include <functional>

#include "../Tests/QuickSortTests.h"
#include "../Tests/MergeSortTests.h"
#include "../Tests/BinaryInsertionSortTests.h"

class TestMenu final : public QMainWindow {
    Q_OBJECT

public:
    explicit TestMenu(QWidget* parent = nullptr) {
        setWindowTitle("Меню тестирования");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* mainLayout = new QVBoxLayout(centralWidget);

        sortingSelector = new QComboBox(this);
        sortingSelector->addItem("Быстрая");
        sortingSelector->addItem("Слиянием");
        sortingSelector->addItem("Бинарная вставка");
        connect(sortingSelector, &QComboBox::currentTextChanged, this, &TestMenu::updateTestList);
        mainLayout->addWidget(sortingSelector);

        testListWidget = new QListWidget(this);
        QFont font = testListWidget->font();
        font.setPointSize(font.pointSize() * 2);
        testListWidget->setFont(font);
        mainLayout->addWidget(testListWidget);

        progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);
        mainLayout->addWidget(progressBar);

        auto* runTestsButton = new QPushButton("Запустить тесты", this);
        connect(runTestsButton, &QPushButton::clicked, this, &TestMenu::runSelectedTests);
        mainLayout->addWidget(runTestsButton);

        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        initTestGroups();
        updateTestList();
    }

private slots:
    void runSelectedTests() {
        progressBar->setValue(0);
        int totalTests = testListWidget->count();
        int successfulTests = 0;

        for (int i = 0; i < testListWidget->count(); ++i) {
            QListWidgetItem* item = testListWidget->item(i);
            auto testFunc = item->data(Qt::UserRole).value<std::function<bool()>>();
            bool success = testFunc();

            item->setText(item->text() + (success ? " - УСПЕШНО" : " - НЕУСПЕШНО"));
            item->setBackground(success ? Qt::green : Qt::red);

            if (success) ++successfulTests;

            progressBar->setValue(((i + 1) * 100) / totalTests);
            QCoreApplication::processEvents();
        }

        QString result = QString("Тесты завершены: %1/%2 успешно.")
                             .arg(successfulTests)
                             .arg(totalTests);
        QLabel* resultLabel = new QLabel(result, this);
        static_cast<QVBoxLayout*>(centralWidget()->layout())->addWidget(resultLabel);
    }

    void updateTestList() {
        QString selectedSort = sortingSelector->currentText();
        testListWidget->clear();

        if (testGroups.contains(selectedSort)) {
            QList<QPair<QString, std::function<bool()>>> tests = testGroups[selectedSort];
            for (const auto& test : tests) {
                auto* item = new QListWidgetItem(test.first, testListWidget);
                QVariant testFuncVariant;
                testFuncVariant.setValue(test.second);
                item->setData(Qt::UserRole, testFuncVariant);
            }
        }
    }

private:
    QComboBox* sortingSelector;
    QListWidget* testListWidget;
    QProgressBar* progressBar;
    QMap<QString, QList<QPair<QString, std::function<bool()>>>> testGroups;

    void initTestGroups() {
        testGroups["Быстрая"] = {
            {"Сортировка по убыванию возраста", []() { return QuickSortDescAgeTest("input.csv"); }},
            {"Сортировка по возрастанию возраста", []() { return QuickSortAscAgeTest("input.csv"); }},
            {"Сортировка по убыванию веса", []() { return QuickSortDescWeightTest("input.csv"); }},
            {"Сортировка по возрастанию веса", []() { return QuickSortAscWeightTest("input.csv"); }},
            {"Сортировка по убыванию роста", []() { return QuickSortDescHeightTest("input.csv"); }},
            {"Сортировка по возрастанию роста", []() { return QuickSortAscHeightTest("input.csv"); }}
        };

        testGroups["Слиянием"] = {
            {"Сортировка по убыванию возраста", []() { return MergeSortDescAgeTest("input.csv"); }},
            {"Сортировка по возрастанию возраста", []() { return MergeSortAscAgeTest("input.csv"); }},
            {"Сортировка по убыванию веса", []() { return MergeSortDescWeightTest("input.csv"); }},
            {"Сортировка по возрастанию веса", []() { return MergeSortAscWeightTest("input.csv"); }},
            {"Сортировка по убыванию роста", []() { return MergeSortDescHeightTest("input.csv"); }},
            {"Сортировка по возрастанию роста", []() { return MergeSortAscHeightTest("input.csv"); }}
        };

        testGroups["Бинарная вставка"] = {
            {"Сортировка по убыванию возраста", []() { return BinaryInsertionSortDescAgeTest("input.csv"); }},
            {"Сортировка по возрастанию возраста", []() { return BinaryInsertionSortAscAgeTest("input.csv"); }},
            {"Сортировка по убыванию веса", []() { return BinaryInsertionSortDescWeightTest("input.csv"); }},
            {"Сортировка по возрастанию веса", []() { return BinaryInsertionSortAscWeightTest("input.csv"); }},
            {"Сортировка по убыванию роста", []() { return BinaryInsertionSortDescHeightTest("input.csv"); }},
            {"Сортировка по возрастанию роста", []() { return BinaryInsertionSortAscHeightTest("input.csv"); }}
        };
    }
};

Q_DECLARE_METATYPE(std::function<bool()>)

#endif // TESTMENU_H
