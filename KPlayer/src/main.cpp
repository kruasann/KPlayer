// src/main.cpp
#include "App.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // �������� ������ (�����������)
    QFile file(":/assets/styles/style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
        file.close();
    }
    else {
        qDebug() << "Not able to load styles file.";
    }

    // �������������� ����������
    App mediaPlayerApp;

    // ���������, ������� �� ���� ����� ��������� ������
    QString filePath;
    if (argc > 1) {
        // ������ �������� ����� ����� ���������� ������ �������� ����� � �����
        filePath = QString::fromUtf8(argv[1]);
        qDebug() << "main() - File path passed:" << filePath;
    }

    // ��������� ���������� � ���������� ������, ���� �� ��� ������
    mediaPlayerApp.start(filePath);

    return app.exec();
}
