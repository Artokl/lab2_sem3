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
        const int totalTests = testListWidget->count();
        int successfulTests = 0;

        for (int i = 0; i < testListWidget->count(); ++i) {
            QListWidgetItem* item = testListWidget->item(i);
            auto testFunc = item->data(Qt::UserRole).value<std::function<bool()>>();
            const bool success = testFunc();

            item->setText(item->text() + (success ? " - УСПЕШНО" : " - НЕУСПЕШНО"));
            item->setBackground(success ? Qt::green : Qt::red);

            if (success) ++successfulTests;

            progressBar->setValue(((i + 1) * 100) / totalTests);
            QCoreApplication::processEvents();
        }

        const QString result = QString("Тесты завершены: %1/%2 успешно.")
                             .arg(successfulTests)
                             .arg(totalTests);
        QLabel* resultLabel = new QLabel(result, this);
        static_cast<QVBoxLayout*>(centralWidget()->layout())->addWidget(resultLabel);
    }

    void updateTestList() {
        const QString selectedSort = sortingSelector->currentText();
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
            {"Сортировка по возрастанию роста", []() { return QuickSortAscHeightTest("input.csv"); }},
            {"Сортировка по убыванию зарплаты", []() { return QuickSortDescSalaryTest("input.csv"); }},
            {"Сортировка по возрастанию зарплаты", []() { return QuickSortAscSalaryTest("input.csv"); }},
            {"Сортировка по убыванию опыта работы", []() { return QuickSortDescExperienceTest("input.csv"); }},
            {"Сортировка по возрастанию опыта работы", []() { return QuickSortAscExperienceTest("input.csv"); }},
            {"Сортировка по убыванию количества сертификатов", []() { return QuickSortDescCertificationsTest("input.csv"); }},
            {"Сортировка по возрастанию количества сертификатов", []() { return QuickSortAscCertificationsTest("input.csv"); }}
        };

        testGroups["Слиянием"] = {
            {"Сортировка по убыванию возраста", []() { return MergeSortDescAgeTest("input.csv"); }},
            {"Сортировка по возрастанию возраста", []() { return MergeSortAscAgeTest("input.csv"); }},
            {"Сортировка по убыванию веса", []() { return MergeSortDescWeightTest("input.csv"); }},
            {"Сортировка по возрастанию веса", []() { return MergeSortAscWeightTest("input.csv"); }},
            {"Сортировка по убыванию роста", []() { return MergeSortDescHeightTest("input.csv"); }},
            {"Сортировка по возрастанию роста", []() { return MergeSortAscHeightTest("input.csv"); }},
            {"Сортировка по убыванию зарплаты", []() { return MergeSortDescSalaryTest("input.csv"); }},
            {"Сортировка по возрастанию зарплаты", []() { return MergeSortAscSalaryTest("input.csv"); }},
            {"Сортировка по убыванию опыта работы", []() { return MergeSortDescExperienceTest("input.csv"); }},
            {"Сортировка по возрастанию опыта работы", []() { return MergeSortAscExperienceTest("input.csv"); }},
            {"Сортировка по убыванию количества сертификатов", []() { return MergeSortDescCertificationsTest("input.csv"); }},
            {"Сортировка по возрастанию количества сертификатов", []() { return MergeSortAscCertificationsTest("input.csv"); }}
        };

        testGroups["Бинарная вставка"] = {
            {"Сортировка по убыванию возраста", []() { return BinaryInsertionSortDescAgeTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию возраста", []() { return BinaryInsertionSortAscAgeTest("binaryinsertion_input.csv"); }},
            {"Сортировка по убыванию веса", []() { return BinaryInsertionSortDescWeightTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию веса", []() { return BinaryInsertionSortAscWeightTest("binaryinsertion_input.csv"); }},
            {"Сортировка по убыванию роста", []() { return BinaryInsertionSortDescHeightTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию роста", []() { return BinaryInsertionSortAscHeightTest("binaryinsertion_input.csv"); }},
            {"Сортировка по убыванию зарплаты", []() { return BinaryInsertionSortDescSalaryTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию зарплаты", []() { return BinaryInsertionSortAscSalaryTest("binaryinsertion_input.csv"); }},
            {"Сортировка по убыванию опыта работы", []() { return BinaryInsertionSortDescExperienceTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию опыта работы", []() { return BinaryInsertionSortAscExperienceTest("binaryinsertion_input.csv"); }},
            {"Сортировка по убыванию количества сертификатов", []() { return BinaryInsertionSortDescCertificationsTest("binaryinsertion_input.csv"); }},
            {"Сортировка по возрастанию количества сертификатов", []() { return BinaryInsertionSortAscCertificationsTest("binaryinsertion_input.csv"); }}
        };
    }
};

Q_DECLARE_METATYPE(std::function<bool()>)

#endif // TESTMENU_H
