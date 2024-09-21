// src/UI/MainScene.h
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "ui_MainScene.h"

class App;

class MainScene : public QMainWindow {
    Q_OBJECT
public:
    explicit MainScene(App* app, QWidget* parent = nullptr);

private slots:
    void onOpenFile();
    void onExitApplication();
    void onFileSelected(const QString& filePath);
    void onHistoryItemClicked(QListWidgetItem* item);

private:
    Ui::MainWindow ui;
    App* app;
};

#endif // MAINSCENE_H
