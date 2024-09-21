// src/UI/MainScene.cpp
#include "MainScene.h"
#include "App.h"
#include "PlayerScene.h"
#include "Utils/FileManager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainScene::MainScene(App* app, QWidget* parent)
    : QMainWindow(parent), app(app)
{
    ui.setupUi(this);  // Инициализируем интерфейс

    // Подключаем сигналы и слоты
    connect(ui.actionOpen, &QAction::triggered, this, &MainScene::onOpenFile);
    connect(ui.actionExit, &QAction::triggered, this, &MainScene::onExitApplication);
    connect(ui.listWidget, &QListWidget::itemClicked, this, &MainScene::onHistoryItemClicked);

    // Загрузка истории
    QStringList history = FileManager::getHistory();
    ui.listWidget->addItems(history);
}

void MainScene::onOpenFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Mediafile");
    if (!filePath.isEmpty()) {
        onFileSelected(filePath);
    }
}

void MainScene::onExitApplication() {
    qApp->quit();
}

void MainScene::onFileSelected(const QString& filePath) {
    FileManager::addToHistory(filePath);
    app->changeScene(new PlayerScene(app, filePath));
}

void MainScene::onHistoryItemClicked(QListWidgetItem* item) {
    QString filePath = item->text();
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Error", "File not found: " + filePath);
        return;
    }
    app->changeScene(new PlayerScene(app, filePath));
}
