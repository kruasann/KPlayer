// src/Utils/FileManager.cpp
#include "FileManager.h"
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>

QStringList FileManager::getHistory() {
    QStringList history;
    QString historyFilePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/history.txt";
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
    QString historyFilePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/history.txt";
    QFile file(historyFilePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << filePath << "\n";
        file.close();
    }
}
