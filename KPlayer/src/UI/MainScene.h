// src/UI/MainScene.h
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QPushButton>

class App;
class QAction;
class QListWidget;
class QLabel;
class QMenu;
class QMenuBar;
class QStatusBar;

class MainScene : public QMainWindow {
    Q_OBJECT
public:
    explicit MainScene(App* app, QWidget* parent = nullptr);
    ~MainScene();

private slots:
    void onOpenFile();
    void onExitApplication();
    void onFileSelected(const QString& filePath);
    void onHistoryItemClicked(QListWidgetItem* item);

private:
    void createActions();
    void createMenus();
    void createCentralWidget();
    void loadHistory();
    void addHistoryItem(const QString& filePath);

    App* app;

    // Меню и действия
    QMenuBar* menubar;
    QMenu* menuFile;
    QAction* actionOpen;
    QAction* actionExit;

    // Центральный виджет и его компоненты
    QWidget* centralWidget;
    QListWidget* listWidget;
    QLabel* label;

    // Статус-бар
    QStatusBar* statusbar;
};

#endif // MAINSCENE_H
