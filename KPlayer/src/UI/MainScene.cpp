// src/UI/MainScene.cpp
#include "MainScene.h"
#include "App.h"
#include "PlayerScene.h"
#include "Utils/FileManager.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QApplication> // Для использования qApp

MainScene::MainScene(App* app, QWidget* parent)
    : QMainWindow(parent), app(app)
{
    // Инициализируем меню и действия
    createActions();
    createMenus();

    // Создаём центральный виджет и его компоненты
    createCentralWidget();

    // Настраиваем статус-бар
    statusbar = new QStatusBar(this);
    setStatusBar(statusbar);

    // Загружаем историю воспроизведения
    loadHistory();

    setWindowTitle("KPlayer - Main Scene");
    resize(800, 600);
}

MainScene::~MainScene()
{
    // Любые необходимые очистки
}

void MainScene::createActions()
{
    // Создание действий для меню
    actionOpen = new QAction("Open", this);
    actionOpen->setShortcut(QKeySequence::Open);
    connect(actionOpen, &QAction::triggered, this, &MainScene::onOpenFile);

    actionExit = new QAction("Exit", this);
    actionExit->setShortcut(QKeySequence::Quit);
    connect(actionExit, &QAction::triggered, this, &MainScene::onExitApplication);
}

void MainScene::createMenus()
{
    // Создание меню и добавление в меню-бар
    menubar = new QMenuBar(this);
    menuFile = new QMenu("File", this);
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);

    menubar->addMenu(menuFile);
    setMenuBar(menubar);
}

void MainScene::createCentralWidget()
{
    // Создание центрального виджета
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создание вертикального layout для центрального виджета
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    // Создание и настройка QLabel
    label = new QLabel("Play History", this);
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(label);

    // Создание и настройка QListWidget
    listWidget = new QListWidget(this);
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(listWidget, &QListWidget::itemClicked, this, &MainScene::onHistoryItemClicked);
    mainLayout->addWidget(listWidget);
}

void MainScene::loadHistory()
{
    // Загрузка истории из FileManager и добавление в QListWidget
    QStringList history = FileManager::getHistory();
    listWidget->clear(); // Очистка существующих элементов
    for (const QString& filePath : history) {
        addHistoryItem(filePath);
    }
}

void MainScene::addHistoryItem(const QString& filePath)
{
    // Проверяем, существует ли уже этот файл в списке
    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem* existingItem = listWidget->item(i);
        QWidget* existingWidget = listWidget->itemWidget(existingItem);
        if (existingWidget) {
            QLabel* existingLabel = existingWidget->findChild<QLabel*>();
            if (existingLabel && existingLabel->text() == filePath) {
                // Найден дубликат, удаляем старый элемент
                delete listWidget->takeItem(i);
                break;
            }
        }
    }

    // Создаём новый элемент списка
    QListWidgetItem* listItem = new QListWidgetItem(listWidget);
    QWidget* itemWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(itemWidget);
    layout->setContentsMargins(2, 2, 2, 2);

    QLabel* fileLabel = new QLabel(filePath, itemWidget);
    layout->addWidget(fileLabel);

    QPushButton* deleteButton = new QPushButton("Delete", itemWidget);

    deleteButton->setMinimumSize(60, 25); // Установка минимального размера
    deleteButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // Фиксированный размер
    deleteButton->setStyleSheet("QPushButton { text-align: center; }");

    deleteButton->setIcon(QIcon(":/assets/icons/delete.png")); // Укажите путь к иконке
    deleteButton->setToolTip("Delete this entry"); // Подсказка при наведении

    layout->addWidget(deleteButton);

    layout->addStretch();

    listItem->setSizeHint(itemWidget->sizeHint());

    listWidget->addItem(listItem);
    listWidget->setItemWidget(listItem, itemWidget);

    // Подключаем кнопку "Delete" к лямбда-функции для удаления элемента
    connect(deleteButton, &QPushButton::clicked, this, [this, listItem, filePath]() {
        // Удаляем файл из истории
        FileManager::removeFromHistory(filePath);
        // Удаляем элемент из списка
        delete listItem;
        // (Опционально) Обновляем статус-бар или выводим сообщение
        statusbar->showMessage("File removed from history.", 2000);
        });
}

void MainScene::onOpenFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Media File", QString(),
        "Media Files (*.mp3 *.wav *.mp4 *.avi *.mkv *.mov)");
    if (!filePath.isEmpty()) {
        onFileSelected(filePath);
    }
}

void MainScene::onExitApplication()
{
    qApp->quit();
}

void MainScene::onFileSelected(const QString& filePath)
{
    FileManager::addToHistory(filePath);
    addHistoryItem(filePath); // Добавляем в QListWidget
    app->changeScene(new PlayerScene(app, filePath));
}

void MainScene::onHistoryItemClicked(QListWidgetItem* item)
{
    // Получаем путь файла из QLabel внутри элемента
    QWidget* itemWidget = listWidget->itemWidget(item);
    if (!itemWidget) return;

    QLabel* fileLabel = itemWidget->findChild<QLabel*>();
    if (!fileLabel) return;

    QString filePath = fileLabel->text();
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Error", "File not found: " + filePath);
        // Удаляем отсутствующий файл из истории
        FileManager::removeFromHistory(filePath);
        delete item; // Удаляем элемент из QListWidget
        // (Опционально) Обновляем статус-бар или выводим сообщение
        statusbar->showMessage("File not found and removed from history.", 2000);
        return;
    }
    app->changeScene(new PlayerScene(app, filePath));
}
