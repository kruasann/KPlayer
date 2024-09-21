// src/UI/Button.cpp
#include "Button.h"

Button::Button(const QString& iconPath, QWidget* parent) : QPushButton(parent) {
    setIcon(QIcon(iconPath));
    setIconSize(QSize(24, 24));
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum); // ��������� ������ �������� ������
    setFlat(true);  // ������� ����������� ����� ������
}

void Button::setIconPath(const QString& iconPath) {
    setIcon(QIcon(iconPath));
}
