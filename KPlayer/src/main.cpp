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

    // Инициализируем приложение
    App mediaPlayerApp;

    // Проверяем, передан ли файл через командную строку
    QString filePath;
    if (argc > 1) {
        // Первый аргумент после имени приложения обычно является путем к файлу
        filePath = QString::fromUtf8(argv[1]);
        qDebug() << "main() - File path passed:" << filePath;
    }

    // Запускаем приложение с переданным файлом, если он был указан
    mediaPlayerApp.start(filePath);

    return app.exec();
}
