// src/UI/Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QString>

class Button : public QPushButton {
    Q_OBJECT
public:
    explicit Button(const QString& iconPath, QWidget* parent = nullptr);
    void setIconPath(const QString& iconPath);
};

#endif // BUTTON_H
