// src/UI/PlayerScene.cpp
#include "PlayerScene.h"
#include "App.h"
#include "Utils/FileManager.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QTime>
#include <QFileInfo>
#include <QDebug>

PlayerScene::PlayerScene(App* app, const QString& filePath, QWidget* parent)
    : QWidget(parent), isPlaying(false), marqueeIndex(0), app(app)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 5, 5, 5);
    mainLayout->setSpacing(5);

    // ����
    menuBar = new QMenuBar(this);
    QMenu* fileMenu = new QMenu("File", this);
    QAction* openAction = new QAction("Open", this);
    QAction* exitAction = new QAction("Exit", this);

    connect(openAction, &QAction::triggered, this, &PlayerScene::openFile);
    connect(exitAction, &QAction::triggered, this, &PlayerScene::exitApplication);

    fileMenu->addAction(openAction);
    fileMenu->addAction(exitAction);
    menuBar->addMenu(fileMenu);

    mainLayout->setMenuBar(menuBar);

    // ����� �������� �����
    mediaLabel = new QLabel(this);
    mediaLabel->setAlignment(Qt::AlignCenter);
    mediaLabel->setStyleSheet("font-weight: bold; font-size: 14px;");
    mainLayout->addWidget(mediaLabel);

    // �����-������
    videoWidget = new QVideoWidget(this);
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(videoWidget, 1);

    // ����������
    mediaPlayer = new MediaPlayer(this);
    mediaPlayer->setVideoOutput(videoWidget);

    // ������ ����������
    QHBoxLayout* controlLayout = new QHBoxLayout();
    controlLayout->setSpacing(10);

    playPauseButton = new Button(":/assets/icons/play.png", this);
    connect(playPauseButton, &QPushButton::clicked, this, &PlayerScene::togglePlayPause);

    stopButton = new Button(":/assets/icons/stop.png", this);
    connect(stopButton, &QPushButton::clicked, this, &PlayerScene::stopPlayback);

    QLabel* volumeLabel = new QLabel("Volume:", this);
    volumeSlider = new Slider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    volumeSlider->setFixedWidth(100);
    connect(volumeSlider, &QSlider::valueChanged, this, &PlayerScene::setVolume);

    controlLayout->addWidget(playPauseButton);
    controlLayout->addWidget(stopButton);
    controlLayout->addStretch();
    controlLayout->addWidget(volumeLabel);
    controlLayout->addWidget(volumeSlider);

    mainLayout->addLayout(controlLayout);

    // �������� � �����
    QHBoxLayout* progressLayout = new QHBoxLayout();
    progressLayout->setSpacing(10);

    progressSlider = new Slider(Qt::Horizontal, this);
    progressSlider->setRange(0, 0);
    connect(progressSlider, &QSlider::sliderMoved, this, &PlayerScene::seek);

    timeLabel = new QLabel("00:00 / 00:00", this);

    progressLayout->addWidget(progressSlider);
    progressLayout->addWidget(timeLabel);

    mainLayout->addLayout(progressLayout);

    setLayout(mainLayout);

    mediaPlayer->setVolume(50);

    connect(mediaPlayer, &MediaPlayer::positionChanged, this, &PlayerScene::updateProgress);
    connect(mediaPlayer, &MediaPlayer::durationChanged, this, [this](qint64 duration) {
        progressSlider->setMaximum(static_cast<int>(duration));
        });
    connect(mediaPlayer, &MediaPlayer::errorOccurred, this, &PlayerScene::handleError);

    marqueeTimer = new QTimer(this);
    connect(marqueeTimer, &QTimer::timeout, this, &PlayerScene::updateMarquee);
    marqueeTimer->start(200);

    if (!filePath.isEmpty()) {
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        FileManager::addToHistory(filePath);
        fullMediaTitle = QFileInfo(filePath).fileName();
        mediaLabel->setText(fullMediaTitle);
        mediaPlayer->play();
        playPauseButton->setIconPath(":/assets/icons/pause.png");
        isPlaying = true;
    }
}

PlayerScene::~PlayerScene()
{
    mediaPlayer->stop();
    delete mediaPlayer;
}

void PlayerScene::togglePlayPause()
{
    if (mediaPlayer->isPlaying()) {
        mediaPlayer->pause();
        playPauseButton->setIconPath(":/assets/icons/play.png");
    }
    else {
        mediaPlayer->play();
        playPauseButton->setIconPath(":/assets/icons/pause.png");
    }
    isPlaying = !isPlaying;
}

void PlayerScene::stopPlayback()
{
    mediaPlayer->stop();
    playPauseButton->setIconPath(":/assets/icons/play.png");
    isPlaying = false;
}

void PlayerScene::setVolume(int value)
{
    mediaPlayer->setVolume(value);
}

void PlayerScene::seek(int value)
{
    mediaPlayer->setPosition(value);
}

void PlayerScene::updateProgress(qint64 position)
{
    if (!progressSlider->isSliderDown()) {
        progressSlider->setValue(static_cast<int>(position));
    }

    qint64 totalTime = mediaPlayer->duration();
    QTime currentTimeObj = QTime::fromMSecsSinceStartOfDay(static_cast<int>(position));
    QTime totalTimeObj = QTime::fromMSecsSinceStartOfDay(static_cast<int>(totalTime));
    QString timeString = currentTimeObj.toString("mm:ss") + " / " + totalTimeObj.toString("mm:ss");
    timeLabel->setText(timeString);
}

void PlayerScene::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Mediafile");
    if (!filePath.isEmpty()) {
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        FileManager::addToHistory(filePath);
        fullMediaTitle = QFileInfo(filePath).fileName();
        marqueeIndex = 0;
        mediaLabel->setText(fullMediaTitle);
        mediaPlayer->play();
        playPauseButton->setIconPath(":/assets/icons/pause.png");
        isPlaying = true;
    }
}

void PlayerScene::exitApplication()
{
    qApp->quit();
}

void PlayerScene::handleError(const QString& errorString)
{
    qDebug() << "Play Error:" << errorString;
    QMessageBox::critical(this, "Error", "Play Error: " + errorString);
}

void PlayerScene::updateMarquee()
{
    if (fullMediaTitle.length() > 20) {
        QString displayText = fullMediaTitle.mid(marqueeIndex, 20);
        mediaLabel->setText(displayText);
        marqueeIndex = (marqueeIndex + 1) % fullMediaTitle.length();
    }
    else {
        mediaLabel->setText(fullMediaTitle);
    }
}
