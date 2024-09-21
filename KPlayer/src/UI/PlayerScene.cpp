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

    // Меню
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

    // Метка названия медиа
    mediaLabel = new QLabel(this);
    mediaLabel->setAlignment(Qt::AlignCenter);
    mediaLabel->setStyleSheet("font-weight: bold; font-size: 14px;");
    mainLayout->addWidget(mediaLabel);

    // Видео-виджет
    videoWidget = new QVideoWidget(this);
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    videoWidget->hide(); // Скрываем по умолчанию
    mainLayout->addWidget(videoWidget, 1);

    // Аудио-визуализатор
    audioVisualizer = new AudioVisualizer(this);
    audioVisualizer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    audioVisualizer->show(); // Показываем по умолчанию
    mainLayout->addWidget(audioVisualizer, 1);

    // Медиаплеер
    mediaPlayer = new MediaPlayer(this);
    mediaPlayer->setVideoOutput(videoWidget);

    // Подключаем сигналы
    connect(mediaPlayer, &MediaPlayer::positionChanged, this, &PlayerScene::updateProgress);
    connect(mediaPlayer, &MediaPlayer::durationChanged, this, [this](qint64 duration) {
        progressSlider->setMaximum(static_cast<int>(duration));
        });
    connect(mediaPlayer, &MediaPlayer::errorOccurred, this, &PlayerScene::handleError);

    // Подключаем сигнал hasVideoChanged
    connect(mediaPlayer, &MediaPlayer::hasVideoChanged, this, &PlayerScene::handleHasVideoChanged);

    // Подключаем аудио-данные к визуализатору
    connect(mediaPlayer, &MediaPlayer::audioDataGenerated, audioVisualizer, &AudioVisualizer::processBuffer);

    // Панель управления
    QHBoxLayout* controlLayout = new QHBoxLayout();
    controlLayout->setSpacing(10);

    // Кнопка "Back"
    backButton = new QPushButton("Back", this);
    connect(backButton, &QPushButton::clicked, this, &PlayerScene::goBack);
    controlLayout->addWidget(backButton);

    // Кнопка Play/Pause
    playPauseButton = new Button(":/assets/icons/play.png", this);
    connect(playPauseButton, &QPushButton::clicked, this, &PlayerScene::togglePlayPause);

    // Кнопка Stop
    stopButton = new Button(":/assets/icons/stop.png", this);
    connect(stopButton, &QPushButton::clicked, this, &PlayerScene::stopPlayback);

    // Ползунок громкости
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

    // Прогресс и время
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

    // Если был передан файл при запуске
    if (!filePath.isEmpty()) {
        qDebug() << "PlayerScene::PlayerScene() - Opening file:" << filePath;

        QFileInfo checkFile(filePath);
        if (!checkFile.exists() || !checkFile.isFile()) {
            qDebug() << "PlayerScene::PlayerScene() - File does not exist or is not a file.";
            QMessageBox::critical(this, "Error", "File does not exist or is not a file.");
            return;
        }

        QUrl mediaUrl = QUrl::fromLocalFile(filePath);
        qDebug() << "PlayerScene::PlayerScene() - Media URL:" << mediaUrl.toString();

        mediaPlayer->setSource(mediaUrl);

        FileManager::addToHistory(filePath);

        fullMediaTitle = checkFile.fileName();
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

void PlayerScene::setMediaSource(const QString& filePath)
{
    if (!filePath.isEmpty()) {
        qDebug() << "PlayerScene::setMediaSource() - Opening file:" << filePath;

        QFileInfo checkFile(filePath);
        if (!checkFile.exists() || !checkFile.isFile()) {
            qDebug() << "PlayerScene::setMediaSource() - File does not exist or is not a file.";
            QMessageBox::critical(this, "Error", "File does not exist or is not a file.");
            return;
        }

        QUrl mediaUrl = QUrl::fromLocalFile(filePath);
        qDebug() << "PlayerScene::setMediaSource() - Media URL:" << mediaUrl.toString();

        mediaPlayer->setSource(mediaUrl);
        FileManager::addToHistory(filePath);
        fullMediaTitle = checkFile.fileName();
        mediaLabel->setText(fullMediaTitle);
        mediaPlayer->play();
        playPauseButton->setIconPath(":/assets/icons/pause.png");
        isPlaying = true;

        // Дополнительная проверка наличия видео
        // Используем QTimer::singleShot, чтобы дождаться загрузки медиа
        QTimer::singleShot(1000, this, [this]() {
            bool hasVideo = mediaPlayer->hasVideo();
            qDebug() << "PlayerScene::setMediaSource() - hasVideo:" << hasVideo;
            handleHasVideoChanged(hasVideo);
            });

        // Немедленно проверить наличие видео и обновить видимость
        bool hasVideo = mediaPlayer->hasVideo();
        handleHasVideoChanged(hasVideo);
    }
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
        qDebug() << "PlayerScene::openFile() - Opening file:" << filePath;

        QFileInfo checkFile(filePath);
        if (!checkFile.exists() || !checkFile.isFile()) {
            qDebug() << "PlayerScene::openFile() - File does not exist or is not a file.";
            QMessageBox::critical(this, "Error", "File does not exist or is not a file.");
            return;
        }

        QUrl mediaUrl = QUrl::fromLocalFile(filePath);
        qDebug() << "PlayerScene::openFile() - Media URL:" << mediaUrl.toString();

        mediaPlayer->setSource(mediaUrl);
        FileManager::addToHistory(filePath);
        fullMediaTitle = checkFile.fileName();
        marqueeIndex = 0;
        mediaLabel->setText(fullMediaTitle);
        mediaPlayer->play();
        playPauseButton->setIconPath(":/assets/icons/pause.png");
        isPlaying = true;

        // Немедленно проверить наличие видео и обновить видимость
        bool hasVideo = mediaPlayer->hasVideo();
        handleHasVideoChanged(hasVideo);
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
        marqueeIndex = (marqueeIndex + 1) % (fullMediaTitle.length() - 19);
    }
    else {
        mediaLabel->setText(fullMediaTitle);
    }
}

// Функция для обработки наличия видео
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
    qDebug() << "PlayerScene::goBack() - Switching to MainScene";
    // Возвращаемся к MainScene
    app->changeScene(new MainScene(app));
}
