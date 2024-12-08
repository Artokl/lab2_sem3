#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "SortMenu.h"
#include "TestMenu.h"

class MainMenu final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainMenu(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Стартовое меню");
        resize(800, 600);

        auto* centralWidget = new QWidget(this);
        auto* mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(20);
        mainLayout->setContentsMargins(50, 50, 50, 50);

        auto* sortButton = new QPushButton("Перейти к сортировке", this);
        auto* testButton = new QPushButton("Перейти к тестам", this);

        sortButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        testButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        mainLayout->addWidget(sortButton);
        mainLayout->addWidget(testButton);

        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        connect(sortButton, &QPushButton::clicked, this, &MainMenu::showSortMenu);
        connect(testButton, &QPushButton::clicked, this, &MainMenu::showTestMenu);
    }

    private slots:
    static void showSortMenu() {
        auto* sortMenu = new SortMenu();
        sortMenu->setAttribute(Qt::WA_DeleteOnClose);
        sortMenu->show();
    }

    static void showTestMenu() {
        auto* testMenu = new TestMenu();
        testMenu->setAttribute(Qt::WA_DeleteOnClose);
        testMenu->show();
    }
};

#endif // MAINMENU_H
