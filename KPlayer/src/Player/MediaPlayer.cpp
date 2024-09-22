// src/Player/MediaPlayer.cpp
#include "MediaPlayer.h"
#include <QRandomGenerator>
#include "UI/AudioVisualizer.h"
#include <QDebug>


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

    // �������������� ������ hasVideoChanged
    connect(player, &QMediaPlayer::hasVideoChanged, this, &MediaPlayer::hasVideoChanged);

    // ������ ��� ��������� �����-������
    audioDataTimer = new QTimer(this);
    connect(audioDataTimer, &QTimer::timeout, this, &MediaPlayer::generateAudioData);
}

MediaPlayer::~MediaPlayer()
{
    // ������� �������
    delete player;
    delete audioOutput;
}

void MediaPlayer::setSource(const QUrl& url)
{
    qDebug() << "MediaPlayer::setSource() - Setting media source:" << url.toString();
    player->setSource(url);
}


void MediaPlayer::play()
{
    qDebug() << "MediaPlayer::play()";
    player->play();

    // ��������� ������ ��������� �����-������
    audioDataTimer->start(100); // ���������� ������ 100 ��

    // ��������� ����� ���� ������������ ��� ������ �������
    int randomType = QRandomGenerator::global()->bounded(2); // 0 ��� 1
    AudioVisualizer::VisualizationType selectedType = static_cast<AudioVisualizer::VisualizationType>(randomType);

    // ������������� ��������� ��� ������������
    emit visualizationTypeChanged(selectedType);

    qDebug() << "Selected visualization type:" << selectedType; // ���������� ����� ��� ��������
}


void MediaPlayer::pause()
{
    qDebug() << "MediaPlayer::pause()";
    player->pause();

    // ������������� ������ ��������� �����-������
    audioDataTimer->stop();
}

void MediaPlayer::stop()
{
    qDebug() << "MediaPlayer::stop()";
    player->stop();

    // ������������� ������ ��������� �����-������
    audioDataTimer->stop();
}

void MediaPlayer::setVolume(int value)
{
    qDebug() << "MediaPlayer::setVolume() - Volume:" << value;
    // ������������� ��������� (0.0 �� 1.0)
    audioOutput->setVolume(value / 100.0);
}

void MediaPlayer::setPosition(qint64 position)
{
    qDebug() << "MediaPlayer::setPosition() - Position:" << position;
    // ������������� ������� ���������������
    player->setPosition(position);
}

qint64 MediaPlayer::position() const
{
    return player->position();
}

qint64 MediaPlayer::duration() const
{
    return player->duration();
}

bool MediaPlayer::isPlaying() const
{
    return player->playbackState() == QMediaPlayer::PlayingState;
}

void MediaPlayer::setVideoOutput(QVideoWidget* videoWidget)
{
    qDebug() << "MediaPlayer::setVideoOutput()";
    // ������������� �����-�����
    player->setVideoOutput(videoWidget);
}

bool MediaPlayer::hasVideo() const
{
    return player->hasVideo();
}

void MediaPlayer::generateAudioData()
{
    // ���������� ��������� �����-������ ��� �������������
    QByteArray data;
    const int sampleCount = 512;
    for (int i = 0; i < sampleCount; ++i) {
        qint16 sample = QRandomGenerator::global()->bounded(-32768, 32767);
        data.append(reinterpret_cast<const char*>(&sample), sizeof(qint16));
    }
    emit audioDataGenerated(data);
}
