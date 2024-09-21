// src/App.cpp
#include "App.h"
#include "UI/MainScene.h"
#include <QApplication>

App::App() {
    mainWindow = new QMainWindow();
    currentScene = nullptr;
}

void App::start() {
    mainWindow->setWindowTitle("K-Player");
    mainWindow->resize(800, 600);
    changeScene(new MainScene(this));
    mainWindow->show();
}

void App::changeScene(QWidget* newScene) {
    if (currentScene) {
        mainWindow->setCentralWidget(nullptr);
        delete currentScene;
    }
    currentScene = newScene;
    mainWindow->setCentralWidget(currentScene);
}
