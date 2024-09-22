// src/App.h
#ifndef APP_H
#define APP_H

#include <QObject>
#include <QMainWindow>
#include "Player/MediaPlayer.h"

class Scene;

class App : public QObject {
    Q_OBJECT
public:
    App();
    MediaPlayer* mediaPlayer() const { return mediaPlayerInstance; }
    void start(const QString& filePath = QString());
    void changeScene(QWidget* newScene);

private:
    QMainWindow* mainWindow;
    MediaPlayer* mediaPlayerInstance;
    QWidget* currentScene;
};

#endif // APP_H
