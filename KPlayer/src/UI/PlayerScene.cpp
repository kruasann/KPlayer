#include "PlayerScene.h"
#include "App.h"
#include "Utils/FileManager.h"
#include "UI/MainScene.h"
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

    // Создание меню
    createActions();
    createMenus();

    // Метка названия медиа
    mediaLabel = new QLabel(this);
    mediaLabel->setAlignment(Qt::AlignCenter);
    mediaLabel->setStyleSheet("font-weight: bold; font-size: 14px;");
    mainLayout->addWidget(mediaLabel);

    // Видео-виджет
    videoWidget = new QVideoWidget(this);
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    videoWidget->hide();
    mainLayout->addWidget(videoWidget, 1);

    // Аудио-визуализатор
    audioVisualizer = new AudioVisualizer(this);
    audioVisualizer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    audioVisualizer->show();
    mainLayout->addWidget(audioVisualizer, 1);

    // Медиаплеер
    mediaPlayer = new MediaPlayer(this);
    mediaPlayer->setVideoOutput(videoWidget);

    connect(mediaPlayer, &MediaPlayer::positionChanged, this, &PlayerScene::updateProgress);
    connect(mediaPlayer, &MediaPlayer::durationChanged, this, [this](qint64 duration) {
        progressSlider->setMaximum(static_cast<int>(duration));
        });
    connect(mediaPlayer, &MediaPlayer::errorOccurred, this, &PlayerScene::handleError);
    connect(mediaPlayer, &MediaPlayer::hasVideoChanged, this, &PlayerScene::handleHasVideoChanged);
    connect(mediaPlayer, &MediaPlayer::audioDataGenerated, audioVisualizer, &AudioVisualizer::processBuffer);

    // Панель управления
    QHBoxLayout* controlLayout = new QHBoxLayout();
    controlLayout->setSpacing(10);

    backButton = new QPushButton("Back", this);
    connect(backButton, &QPushButton::clicked, this, &PlayerScene::goBack);
    controlLayout->addWidget(backButton);

    rewindButton = new Button(":/assets/icons/minus-s.png", this);
    connect(rewindButton, &QPushButton::clicked, this, &PlayerScene::rewind);
    controlLayout->addWidget(rewindButton);

    playPauseButton = new Button(":/assets/icons/play.png", this);
    connect(playPauseButton, &QPushButton::clicked, this, &PlayerScene::togglePlayPause);
    controlLayout->addWidget(playPauseButton);

    fastForwardButton = new Button(":/assets/icons/plus-s.png", this);
    connect(fastForwardButton, &QPushButton::clicked, this, &PlayerScene::fastForward);
    controlLayout->addWidget(fastForwardButton);

    stopButton = new Button(":/assets/icons/stop.png", this);
    connect(stopButton, &QPushButton::clicked, this, &PlayerScene::stopPlayback);
    controlLayout->addWidget(stopButton);

    QLabel* volumeLabel = new QLabel("Volume:", this);
    volumeSlider = new Slider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    volumeSlider->setFixedWidth(100);
    connect(volumeSlider, &QSlider::valueChanged, this, &PlayerScene::setVolume);

    controlLayout->addStretch();
    controlLayout->addWidget(volumeLabel);
    controlLayout->addWidget(volumeSlider);

    mainLayout->addLayout(controlLayout);

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

    marqueeTimer = new QTimer(this);
    connect(marqueeTimer, &QTimer::timeout, this, &PlayerScene::updateMarquee);
    marqueeTimer->start(200);

    if (!filePath.isEmpty()) {
        setMediaSource(filePath);
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

void PlayerScene::rewind()
{
    qint64 currentPosition = mediaPlayer->position();
    mediaPlayer->setPosition(currentPosition - 10000);
}

void PlayerScene::fastForward()
{
    qint64 currentPosition = mediaPlayer->position();
    mediaPlayer->setPosition(currentPosition + 10000);
}

void PlayerScene::setMediaSource(const QString& filePath)
{
    QFileInfo checkFile(filePath);
    if (!checkFile.exists() || !checkFile.isFile()) {
        QMessageBox::critical(this, "Error", "File does not exist or is not a file.");
        return;
    }
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
    FileManager::addToHistory(filePath);
    fullMediaTitle = checkFile.fileName();
    mediaLabel->setText(fullMediaTitle);
    mediaPlayer->play();
    playPauseButton->setIconPath(":/assets/icons/pause.png");
    isPlaying = true;
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
    timeLabel->setText(currentTimeObj.toString("mm:ss") + " / " + totalTimeObj.toString("mm:ss"));
}

void PlayerScene::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Mediafile");
    if (!filePath.isEmpty()) {
        setMediaSource(filePath);
    }
}

void PlayerScene::exitApplication()
{
    qApp->quit();
}

void PlayerScene::handleError(const QString& errorString)
{
    QMessageBox::critical(this, "Error", "Play Error: " + errorString);
}

void PlayerScene::updateMarquee()
{
    if (fullMediaTitle.length() > 20) {
        QString displayText = fullMediaTitle.mid(marqueeIndex, 20);
        mediaLabel->setText(displayText);
        marqueeIndex = (marqueeIndex + 1) % (fullMediaTitle.length() - 19);
    }
    else {
        mediaLabel->setText(fullMediaTitle);
    }
}

void PlayerScene::handleHasVideoChanged(bool hasVideo)
{
    if (hasVideo) {
        videoWidget->show();
        audioVisualizer->hide();
    }
    else {
        videoWidget->hide();
        audioVisualizer->show();
    }
}

void PlayerScene::goBack()
{
    app->changeScene(new MainScene(app));
}

void PlayerScene::createActions()
{
    // Создание действий для меню
    actionOpen = new QAction("Open", this);
    actionOpen->setShortcut(QKeySequence::Open);
    connect(actionOpen, &QAction::triggered, this, &PlayerScene::openFile);

    actionExit = new QAction("Exit", this);
    actionExit->setShortcut(QKeySequence::Quit);
    connect(actionExit, &QAction::triggered, this, &PlayerScene::exitApplication);

    actionRewind = new QAction("Rewind 10s", this);
    actionRewind->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Left)); // Изменение оператора на '|'
    connect(actionRewind, &QAction::triggered, this, &PlayerScene::rewind);

    actionFastForward = new QAction("Fast Forward 10s", this);
    actionFastForward->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Right)); // Изменение оператора на '|'
    connect(actionFastForward, &QAction::triggered, this, &PlayerScene::fastForward);

    actionPlayPause = new QAction("Play/Pause", this);
    actionPlayPause->setShortcut(QKeySequence(Qt::Key_Space));
    connect(actionPlayPause, &QAction::triggered, this, &PlayerScene::togglePlayPause);
}


void PlayerScene::createMenus()
{
    menuBar = new QMenuBar(this);
    menuFile = new QMenu("File", this);
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);

    menuPlayback = new QMenu("Playback", this);
    menuPlayback->addAction(actionPlayPause);
    menuPlayback->addAction(actionRewind);
    menuPlayback->addAction(actionFastForward);

    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuPlayback);
    layout()->setMenuBar(menuBar);
}
