#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "SortMenu.h"
#include "TestMenu.h"

class MainMenu : public QMainWindow {
    Q_OBJECT

public:
    explicit MainMenu(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Добро пожаловать");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* mainLayout = new QHBoxLayout(centralWidget);

        auto* buttonPanel = new QVBoxLayout();
        auto* headerLabel = new QLabel("Выберите действие:", this);
        headerLabel->setAlignment(Qt::AlignCenter);

        auto* sortButton = new QPushButton("Перейти к сортировке", this);
        auto* testButton = new QPushButton("Перейти к тестам", this);

        buttonPanel->addWidget(headerLabel);
        buttonPanel->addWidget(sortButton);
        buttonPanel->addWidget(testButton);
        buttonPanel->addStretch();

        auto* contentArea = new QLabel("Здесь будет отображаться информация или окно выбора", this);
        contentArea->setAlignment(Qt::AlignCenter);

        mainLayout->addLayout(buttonPanel);
        mainLayout->addWidget(contentArea);

        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        connect(sortButton, &QPushButton::clicked, this, &MainMenu::showSortMenu);
        connect(testButton, &QPushButton::clicked, this, &MainMenu::showTestMenu);
    }

private slots:
    void showSortMenu() {
        auto* sortMenu = new SortMenu();
        sortMenu->setAttribute(Qt::WA_DeleteOnClose);
        sortMenu->show();
    }

    void showTestMenu() {
        auto* testMenu = new TestMenu();
        testMenu->setAttribute(Qt::WA_DeleteOnClose);
        testMenu->show();
    }
};

#endif // MAINMENU_H
