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
        // ���� ������� ����, ��������� ����� ������ �����
        changeScene(new PlayerScene(this, filePath));
    }
    else {
        // ����� ���������� ��������� ����� � ��������
        changeScene(new MainScene(this));
    }

    mainWindow->show();
}

void App::changeScene(QWidget* newScene) {
    if (currentScene) {
        currentScene->deleteLater();  // ����������� ���������� �����
    }
    currentScene = newScene;
    mainWindow->setCentralWidget(currentScene);  // ������������� ����� ����� ��� ����������� ������
}
