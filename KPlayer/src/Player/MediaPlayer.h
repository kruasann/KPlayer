// src/Player/MediaPlayer.h
#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>

/**
 * @brief Класс MediaPlayer инкапсулирует функциональность воспроизведения медиа.
 */
class MediaPlayer : public QObject {
    Q_OBJECT
public:
    explicit MediaPlayer(QObject* parent = nullptr);
    ~MediaPlayer();

    void setSource(const QUrl& url);
    void play();
    void pause();
    void stop();
    void setVolume(int value);
    void setPosition(qint64 position);
    qint64 position() const;
    qint64 duration() const;
    bool isPlaying() const;
    void setVideoOutput(QVideoWidget* videoWidget);

signals:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void errorOccurred(const QString& errorString);

private:
    QMediaPlayer* player;      ///< Объект медиаплеера
    QAudioOutput* audioOutput; ///< Объект аудиовыхода
};

#endif // MEDIA_PLAYER_H
