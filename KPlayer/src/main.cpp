// src/main.cpp
#include "App.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Загрузка стилей (опционально)
    QFile file(":/assets/styles/style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
        file.close();
    }
    else {
        qDebug() << "Not able to load styles file.";
    }

    App mediaPlayerApp;
    mediaPlayerApp.start();
    return app.exec();
}
