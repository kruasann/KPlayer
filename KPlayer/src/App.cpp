// src/App.cpp
#include "App.h"
#include "UI/MainScene.h"
#include "UI/PlayerScene.h"
#include <QApplication>
#include <QDebug>
#include <QIcon>

App::App() {
    mainWindow = new QMainWindow();
    currentScene = nullptr;
}

    // test

void App::start(const QString& filePath) {
    mainWindow->setWindowTitle("K-Player");
    mainWindow->setWindowIcon(QIcon(":/assets/icons/app_icon.ico"));
    mainWindow->resize(800, 600);

    if (!filePath.isEmpty()) {
        qDebug() << "App::start() - Opening file:" << filePath;
        // Если передан файл, открываем сцену плеера сразу
        changeScene(new PlayerScene(this, filePath));
    }
    else {
        // Иначе показываем начальную сцену с историей
        changeScene(new MainScene(this));
    }

    mainWindow->show();
}

void App::changeScene(QWidget* newScene) {
    if (currentScene) {
        currentScene->deleteLater();  // Освобождаем предыдущую сцену
    }
    currentScene = newScene;
    mainWindow->setCentralWidget(currentScene);  // Устанавливаем новую сцену как центральный виджет
}
