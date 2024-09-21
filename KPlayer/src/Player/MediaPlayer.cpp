// src/Player/MediaPlayer.cpp
#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QObject* parent)
    : QObject(parent)
{
    // Инициализируем медиаплеер и аудиовыход
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // Устанавливаем аудиовыход для медиаплеера
    player->setAudioOutput(audioOutput);

    // Подключаем сигналы медиаплеера к нашим сигналам
    connect(player, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);

    // Обрабатываем ошибки воспроизведения
    connect(player, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error error) {
        Q_UNUSED(error);
        emit errorOccurred(player->errorString());
        });
}

MediaPlayer::~MediaPlayer()
{
    // Очищаем ресурсы
    delete player;
    delete audioOutput;
}

void MediaPlayer::setSource(const QUrl& url)
{
    // Устанавливаем источник медиа
    player->setSource(url);
}

void MediaPlayer::play()
{
    // Начинаем воспроизведение
    player->play();
}

void MediaPlayer::pause()
{
    // Ставим на паузу
    player->pause();
}

void MediaPlayer::stop()
{
    // Останавливаем воспроизведение
    player->stop();
}

void MediaPlayer::setVolume(int value)
{
    // Устанавливаем громкость (0.0 до 1.0)
    audioOutput->setVolume(value / 100.0);
}

void MediaPlayer::setPosition(qint64 position)
{
    // Устанавливаем позицию воспроизведения
    player->setPosition(position);
}

qint64 MediaPlayer::position() const
{
    // Получаем текущую позицию воспроизведения
    return player->position();
}

qint64 MediaPlayer::duration() const
{
    // Получаем длительность медиа
    return player->duration();
}

bool MediaPlayer::isPlaying() const
{
    // Проверяем, воспроизводится ли медиа
    return player->playbackState() == QMediaPlayer::PlayingState;
}

void MediaPlayer::setVideoOutput(QVideoWidget* videoWidget)
{
    // Устанавливаем видео-вывод
    player->setVideoOutput(videoWidget);
}
