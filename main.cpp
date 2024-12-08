#include <QApplication>
#include "UI/MainMenu.h"

void applyStyleSheet(QApplication &app) {
    const QString styleSheet = R"(
        QMainWindow {
            background-color: #2A003F;
            color: #E6E6FA;
            font-family: 'Roboto';
            font-size: 15px;
        }

        QLabel {
            color: #E6E6FA;
            font-size: 18px;
        }

        QPushButton {
            background-color: #8A2BE2;
            color: #FFFFFF;
            border: none;
            padding: 12px;
            font-size: 15px;
            font-weight: bold;
            border-radius: 5px;
        }

        QPushButton:hover {
            background-color: #7A1FC4;
        }

        QPushButton:pressed {
            background-color: #6919A4;
        }

        QComboBox {
            background-color: #3B0B45;
            color: #E6E6FA;
            border: 1px solid #8A2BE2;
            padding: 7px;
            font-size: 15px;
            border-radius: 3px;
        }

        QComboBox::drop-down {
            border: none;
            background-color: #8A2BE2;
            width: 20px;
        }

        QComboBox::down-arrow {
            image: url(:/icons/down-arrow-purple.png);
        }

        QComboBox QAbstractItemView {
            background-color: #3B0B45;
            color: #E6E6FA;
            selection-background-color: #8A2BE2;
            selection-color: #FFFFFF;
            border: 1px solid #8A2BE2;
        }

        QLineEdit {
            background-color: #3B0B45;
            color: #E6E6FA;
            border: 1px solid #8A2BE2;
            padding: 7px;
            font-size: 15px;
            border-radius: 3px;
        }

        QProgressBar {
            background-color: #3B0B45;
            border: 1px solid #8A2BE2;
            border-radius: 3px;
            text-align: center;
            color: #FFFFFF;
        }

        QProgressBar::chunk {
            background-color: #8A2BE2;
        }

        QFrame {
            background-color: #3B0B45;
            border: none;
            margin: 15px 0;
        }

        QTextEdit {
            background-color: #3B0B45;
            color: #E6E6FA;
            border: 1px solid #8A2BE2;
            padding: 12px;
            font-size: 15px;
            border-radius: 3px;
        }

        QTextEdit QScrollBar:vertical {
            border: none;
            background: #2A003F;
            width: 12px;
        }

        QTextEdit QScrollBar::handle:vertical {
            background: #8A2BE2;
            border-radius: 6px;
        }

        QTextEdit QScrollBar::add-line:vertical, QTextEdit QScrollBar::sub-line:vertical {
            height: 0px;
        }
    )";
    app.setStyleSheet(styleSheet);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    applyStyleSheet(app);
    MainMenu mainMenu;
    mainMenu.show();

    return QApplication::exec();


/*    std::string fileName = "binary_input.csv";
    GeneratePersons(fileName, 10000);*/
}
