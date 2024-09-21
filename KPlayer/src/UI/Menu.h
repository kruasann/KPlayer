// src/UI/Menu.h
#ifndef MENU_H
#define MENU_H

#include <QMenuBar>

class Menu : public QMenuBar {
    Q_OBJECT
public:
    explicit Menu(QWidget* parent = nullptr);
signals:
    void fileSelected(const QString& filePath);
private slots:
    void openFile();
};

#endif // MENU_H
