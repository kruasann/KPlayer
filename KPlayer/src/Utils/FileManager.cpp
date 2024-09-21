// src/Utils/FileManager.cpp
#include "FileManager.h"
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>

QStringList FileManager::getHistory() {
    QStringList history;
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataLocation);
    if (!dir.exists()) {
        dir.mkpath("."); // Создаём директорию, если она не существует
    }
    QString historyFilePath = appDataLocation + "/history.txt";
    QFile file(historyFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                history.append(line);
            }
        }
        file.close();
    }
    return history;
}

void FileManager::addToHistory(const QString& filePath) {
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataLocation);
    if (!dir.exists()) {
        dir.mkpath("."); // Создаём директорию, если она не существует
    }
    QString historyFilePath = appDataLocation + "/history.txt";
    QFile file(historyFilePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << filePath << "\n";
        file.close();
    }
}

void FileManager::removeFromHistory(const QString& filePath) {
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataLocation);
    if (!dir.exists()) {
        dir.mkpath("."); // Создаём директорию, если она не существует
    }
    QString historyFilePath = appDataLocation + "/history.txt";
    QFile file(historyFilePath);
    QStringList history;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty() && line != filePath) { // Пропускаем удаляемый путь
                history.append(line);
            }
        }
        file.close();
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& path : history) {
            out << path << "\n";
        }
        file.close();
    }
}
