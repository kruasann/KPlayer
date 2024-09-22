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
#include <QComboBox>
#include <QDebug>
#include <QApplication>
#include <QSettings>

MainScene::MainScene(App* app, QWidget* parent)
    : QMainWindow(parent), app(app)
{
    // �������������� ���� � ��������
    createActions();
    createMenus();

    // ������ ����������� ������ � ��� ����������
    createCentralWidget();

    // ����������� ������-���
    statusbar = new QStatusBar(this);
    setStatusBar(statusbar);

    // ��������� ������� ���������������
    loadHistory();

    // �������� ���������� ����
    loadSavedStyle();

    setWindowTitle("KPlayer - Main Scene");
    resize(800, 600);
}

MainScene::~MainScene()
{
    // ����� ����������� �������
}

void MainScene::createActions()
{
    // �������� �������� ��� ����
    actionOpen = new QAction("Open", this);
    actionOpen->setShortcut(QKeySequence::Open);
    connect(actionOpen, &QAction::triggered, this, &MainScene::onOpenFile);

    actionExit = new QAction("Exit", this);
    actionExit->setShortcut(QKeySequence::Quit);
    connect(actionExit, &QAction::triggered, this, &MainScene::onExitApplication);
}

void MainScene::createMenus() {
    menubar = new QMenuBar(this);

    // File Menu
    menuFile = new QMenu("File", this);
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);

    // Settings Menu
    menuSettings = new QMenu("Settings", this);

    // Create a combo box for selecting styles
    styleComboBox = new QComboBox(this);
    styleComboBox->addItem("NordStyle");
    styleComboBox->addItem("LightTheme");
    styleComboBox->addItem("PastelDream");
    styleComboBox->addItem("SolarizedDark");
    styleComboBox->addItem("MonokaiPro");
    styleComboBox->addItem("OceanBreeze");

    // Add combo box to a QWidgetAction
    QWidgetAction* styleAction = new QWidgetAction(this);
    QWidget* comboBoxWidget = new QWidget(this);
    QHBoxLayout* comboBoxLayout = new QHBoxLayout(comboBoxWidget);
    comboBoxLayout->addWidget(new QLabel("Select Theme:", this));
    comboBoxLayout->addWidget(styleComboBox);
    styleAction->setDefaultWidget(comboBoxWidget);

    menuSettings->addAction(styleAction);

    // Add menus to menubar
    menubar->addMenu(menuFile);
    menubar->addMenu(menuSettings);

    // Ensure the menubar is set to the main window
    setMenuBar(menubar);

    // Connect the style combo box to the slot
    connect(styleComboBox, &QComboBox::currentTextChanged, this, &MainScene::onStyleChanged);
}


void MainScene::onStyleChanged(const QString& styleName) {
    QString stylePath = ":/assets/styles/" + styleName + ".qss";
    loadStyle(stylePath);

    // ��������� ��������� ���� � QSettings
    QSettings settings("Kruasann", "KPlayer");
    settings.setValue("theme", styleName);

    statusbar->showMessage("Theme changed to " + styleName, 2000);
}

void MainScene::loadStyle(const QString& stylePath) {
    QFile file(stylePath);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
        file.close();
    }
    else {
        statusbar->showMessage("Failed to load style: " + stylePath, 2000);
    }
}

void MainScene::loadSavedStyle() {
    // ��������� ���������� ���� �� QSettings
    QSettings settings("Kruasann", "KPlayer");
    QString savedStyle = settings.value("theme", "NordStyle").toString();  // �� ��������� NordStyle

    // ������������� ���������� ����
    styleComboBox->setCurrentText(savedStyle);
    onStyleChanged(savedStyle);  // ��������� �����
}

void MainScene::createCentralWidget()
{
    // �������� ������������ �������
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // �������� ������������� layout ��� ������������ �������
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    // �������� � ��������� QLabel
    label = new QLabel("Play History", this);
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(label);

    // �������� � ��������� QListWidget
    listWidget = new QListWidget(this);
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(listWidget, &QListWidget::itemClicked, this, &MainScene::onHistoryItemClicked);
    mainLayout->addWidget(listWidget);
}

void MainScene::loadHistory()
{
    // �������� ������� �� FileManager � ���������� � QListWidget
    QStringList history = FileManager::getHistory();
    listWidget->clear(); // ������� ������������ ���������
    for (const QString& filePath : history) {
        addHistoryItem(filePath);
    }
}

void MainScene::addHistoryItem(const QString& filePath)
{
    // ���������, ���������� �� ��� ���� ���� � ������
    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem* existingItem = listWidget->item(i);
        QWidget* existingWidget = listWidget->itemWidget(existingItem);
        if (existingWidget) {
            QLabel* existingLabel = existingWidget->findChild<QLabel*>();
            if (existingLabel && existingLabel->text() == filePath) {
                // ������ ��������, ������� ������ �������
                delete listWidget->takeItem(i);
                break;
            }
        }
    }

    // ������ ����� ������� ������
    QListWidgetItem* listItem = new QListWidgetItem(listWidget);
    QWidget* itemWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(itemWidget);
    layout->setContentsMargins(2, 2, 2, 2);

    QLabel* fileLabel = new QLabel(filePath, itemWidget);
    layout->addWidget(fileLabel);

    QPushButton* deleteButton = new QPushButton("Delete", itemWidget);

    deleteButton->setMinimumSize(60, 25); // ��������� ������������ �������
    deleteButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // ������������� ������
    deleteButton->setStyleSheet("QPushButton { text-align: center; }");

    deleteButton->setIcon(QIcon(":/assets/icons/delete.png")); // ������� ���� � ������
    deleteButton->setToolTip("Delete this entry"); // ��������� ��� ���������

    layout->addWidget(deleteButton);

    layout->addStretch();

    listItem->setSizeHint(itemWidget->sizeHint());

    listWidget->addItem(listItem);
    listWidget->setItemWidget(listItem, itemWidget);

    // ���������� ������ "Delete" � ������-������� ��� �������� ��������
    connect(deleteButton, &QPushButton::clicked, this, [this, listItem, filePath]() {
        // ������� ���� �� �������
        FileManager::removeFromHistory(filePath);
        // ������� ������� �� ������
        delete listItem;
        // (�����������) ��������� ������-��� ��� ������� ���������
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
    FileManager::addToHistory(filePath);  // ��������� ���� � �������
    addHistoryItem(filePath);  // ��������� ���� � ������ �������

    // ��������� �� ����� �����
    app->changeScene(new PlayerScene(app, filePath));
}


void MainScene::onHistoryItemClicked(QListWidgetItem* item)
{
    // �������� ���� ����� �� QLabel ������ ��������
    QWidget* itemWidget = listWidget->itemWidget(item);
    if (!itemWidget) return;

    QLabel* fileLabel = itemWidget->findChild<QLabel*>();
    if (!fileLabel) return;

    QString filePath = fileLabel->text();
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Error", "File not found: " + filePath);
        // ������� ������������� ���� �� �������
        FileManager::removeFromHistory(filePath);
        delete item; // ������� ������� �� QListWidget
        // (�����������) ��������� ������-��� ��� ������� ���������
        statusbar->showMessage("File not found and removed from history.", 2000);
        return;
    }
    app->changeScene(new PlayerScene(app, filePath));
}
