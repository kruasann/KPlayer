// src/main.cpp
#include "App.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QSettings>  // ��� ������ � �����������

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // ��������� ���������� ����, ���������� � QSettings
    QSettings settings("Kruasann", "KPlayer");  // ���������� ���������� ������������ ���
    QString savedStyle = settings.value("theme", "NordStyle").toString();  // �� ��������� NordStyle

    // �������� ������ (�����������)
    QString stylePath = ":/assets/styles/" + savedStyle + ".qss";
    QFile file(stylePath);
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
