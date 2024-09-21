// src/UI/PlayerScene.h
#ifndef PLAYER_SCENE_H
#define PLAYER_SCENE_H

#include "Scene.h"
#include "UI/Button.h"
#include "UI/Slider.h"
#include "Player/MediaPlayer.h"
#include "UI/AudioVisualizer.h"
#include <QWidget>
#include <QLabel>
#include <QVideoWidget>
#include <QMenuBar>
#include <QTimer>
#include <QPushButton> // Добавлено

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
    void handleHasVideoChanged(bool hasVideo);
    void goBack(); // Новый слот

private:
    void setMediaSource(const QString& filePath);

    MediaPlayer* mediaPlayer;
    Button* playPauseButton;
    Button* stopButton;
    Slider* volumeSlider;
    Slider* progressSlider;
    QLabel* timeLabel;
    QLabel* mediaLabel;
    QMenuBar* menuBar;
    QVideoWidget* videoWidget;
    AudioVisualizer* audioVisualizer;
    QTimer* marqueeTimer;
    QPushButton* backButton; // Кнопка "Back"
    QString fullMediaTitle;
    int marqueeIndex;
    bool isPlaying;
    App* app;
};

#endif // PLAYER_SCENE_H
