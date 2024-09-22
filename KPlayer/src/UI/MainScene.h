#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QComboBox>  // Добавляем для выпадающего списка
#include <QPushButton>
#include <QWidgetAction>


class App;
class QAction;
class QListWidget;
class QLabel;
class QMenu;
class QMenuBar;
class QStatusBar;

class MainScene : public QMainWindow {
    Q_OBJECT
public:
    explicit MainScene(App* app, QWidget* parent = nullptr);
    ~MainScene();

private slots:
    void onOpenFile();
    void onExitApplication();
    void onFileSelected(const QString& filePath);
    void onHistoryItemClicked(QListWidgetItem* item);
    void onStyleChanged(const QString& styleName);  // Новый слот для изменения стиля

private:
    void createActions();
    void createMenus();
    void createCentralWidget();
    void loadHistory();
    void loadSavedStyle();
    void addHistoryItem(const QString& filePath);
    void loadStyle(const QString& stylePath);  // Новый метод для загрузки стиля

    App* app;

    // Меню и действия
    QMenuBar* menubar;
    QMenu* menuFile;
    QMenu* menuSettings;  // Новое меню для настроек
    QAction* actionOpen;
    QAction* actionExit;

    QComboBox* styleComboBox;  // Выпадающий список для выбора стиля

    // Центральный виджет и его компоненты
    QWidget* centralWidget;
    QListWidget* listWidget;
    QLabel* label;

    // Статус-бар
    QStatusBar* statusbar;
};

#endif // MAINSCENE_H
