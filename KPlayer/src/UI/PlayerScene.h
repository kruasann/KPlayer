// src/UI/PlayerScene.h
#ifndef PLAYER_SCENE_H
#define PLAYER_SCENE_H

#include "Scene.h"
#include "UI/Button.h"
#include "UI/Slider.h"
#include "Player/MediaPlayer.h"
#include <QWidget>
#include <QLabel>
#include <QVideoWidget>
#include <QMenuBar>
#include <QTimer>

class App;

class PlayerScene : public QWidget {
    Q_OBJECT
public:
    explicit PlayerScene(App* app, const QString& filePath = QString(), QWidget* parent = nullptr);
    ~PlayerScene();

private slots:
    void togglePlayPause();
    void stopPlayback();
    void setVolume(int value);
    void seek(int value);
    void updateProgress(qint64 position);
    void openFile();
    void exitApplication();
    void handleError(const QString& errorString);
    void updateMarquee();

private:
    MediaPlayer* mediaPlayer;
    Button* playPauseButton;
    Button* stopButton;
    Slider* volumeSlider;
    Slider* progressSlider;
    QLabel* timeLabel;
    QLabel* mediaLabel;
    QMenuBar* menuBar;
    QVideoWidget* videoWidget;
    QTimer* marqueeTimer;
    QString fullMediaTitle;
    int marqueeIndex;
    bool isPlaying;
    App* app;
};

#endif // PLAYER_SCENE_H
