// src/Player/MediaPlayer.cpp
#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QObject* parent)
    : QObject(parent)
{
    // �������������� ���������� � ����������
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // ������������� ���������� ��� �����������
    player->setAudioOutput(audioOutput);

    // ���������� ������� ����������� � ����� ��������
    connect(player, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);

    // ������������ ������ ���������������
    connect(player, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error error) {
        Q_UNUSED(error);
        emit errorOccurred(player->errorString());
        });
}

MediaPlayer::~MediaPlayer()
{
    // ������� �������
    delete player;
    delete audioOutput;
}

void MediaPlayer::setSource(const QUrl& url)
{
    // ������������� �������� �����
    player->setSource(url);
}

void MediaPlayer::play()
{
    // �������� ���������������
    player->play();
}

void MediaPlayer::pause()
{
    // ������ �� �����
    player->pause();
}

void MediaPlayer::stop()
{
    // ������������� ���������������
    player->stop();
}

void MediaPlayer::setVolume(int value)
{
    // ������������� ��������� (0.0 �� 1.0)
    audioOutput->setVolume(value / 100.0);
}

void MediaPlayer::setPosition(qint64 position)
{
    // ������������� ������� ���������������
    player->setPosition(position);
}

qint64 MediaPlayer::position() const
{
    // �������� ������� ������� ���������������
    return player->position();
}

qint64 MediaPlayer::duration() const
{
    // �������� ������������ �����
    return player->duration();
}

bool MediaPlayer::isPlaying() const
{
    // ���������, ��������������� �� �����
    return player->playbackState() == QMediaPlayer::PlayingState;
}

void MediaPlayer::setVideoOutput(QVideoWidget* videoWidget)
{
    // ������������� �����-�����
    player->setVideoOutput(videoWidget);
}
