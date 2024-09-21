// src/UI/Scene.cpp
#include "Scene.h"

Scene::Scene(App* app, QWidget* parent) : QWidget(parent), app(app) {
    // ”станавливаем политику размеров по умолчанию
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
