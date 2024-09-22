#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QComboBox>  // ��������� ��� ����������� ������
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
    void onStyleChanged(const QString& styleName);  // ����� ���� ��� ��������� �����

private:
    void createActions();
    void createMenus();
    void createCentralWidget();
    void loadHistory();
    void loadSavedStyle();
    void addHistoryItem(const QString& filePath);
    void loadStyle(const QString& stylePath);  // ����� ����� ��� �������� �����

    App* app;

    // ���� � ��������
    QMenuBar* menubar;
    QMenu* menuFile;
    QMenu* menuSettings;  // ����� ���� ��� ��������
    QAction* actionOpen;
    QAction* actionExit;

    QComboBox* styleComboBox;  // ���������� ������ ��� ������ �����

    // ����������� ������ � ��� ����������
    QWidget* centralWidget;
    QListWidget* listWidget;
    QLabel* label;

    // ������-���
    QStatusBar* statusbar;
};

#endif // MAINSCENE_H
