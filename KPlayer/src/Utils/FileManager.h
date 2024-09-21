// src/Utils/FileManager.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QStringList>

class FileManager {
public:
    static QStringList getHistory();
    static void addToHistory(const QString& filePath);
    static void removeFromHistory(const QString& filePath); // �������� �����
};

#endif // FILEMANAGER_H
