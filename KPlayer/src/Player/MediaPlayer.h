// src/Player/MediaPlayer.h
#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QTimer>
#include <QByteArray>

/**
 * @brief ����� MediaPlayer ������������� ���������������� ��������������� �����.
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
    bool hasVideo() const; // ����������� �����

signals:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void errorOccurred(const QString& errorString);
    void hasVideoChanged(bool hasVideo); // ����� ������
    void audioDataGenerated(const QByteArray& data);

private slots:
    void generateAudioData();

private:
    QMediaPlayer* player;       ///< ������ �����������
    QAudioOutput* audioOutput;  ///< ������ �����������
    QTimer* audioDataTimer;     ///< ������ ��� ��������� �����-������
};

#endif // MEDIA_PLAYER_H
