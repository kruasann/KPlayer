// src/UI/Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

class App;

class Scene : public QWidget {
    Q_OBJECT
public:
    explicit Scene(App* app, QWidget* parent = nullptr);
protected:
    App* app;
};

#endif // SCENE_H
