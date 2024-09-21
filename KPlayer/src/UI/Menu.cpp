// src/UI/Menu.cpp
#include "Menu.h"
#include <QFileDialog>
#include <QAction>

Menu::Menu(QWidget* parent) : QMenuBar(parent) {
    QMenu* fileMenu = addMenu("File");
    QAction* openAction = new QAction(QIcon(":/assets/icons/open.png"), "Open", this);
    connect(openAction, &QAction::triggered, this, &Menu::openFile);
    fileMenu->addAction(openAction);
}

void Menu::openFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choose a mediafile");
    if (!filePath.isEmpty()) {
        emit fileSelected(filePath);
    }
}
