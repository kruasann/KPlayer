// src/App.h
#ifndef APP_H
#define APP_H

#include <QObject>
#include <QMainWindow>

class Scene;

class App : public QObject {
    Q_OBJECT
public:
    App();
    void start();
    void changeScene(QWidget* newScene);

private:
    QMainWindow* mainWindow;
    QWidget* currentScene;
};

#endif // APP_H
