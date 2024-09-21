// src/UI/Slider.h
#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

class Slider : public QSlider {
    Q_OBJECT
public:
    explicit Slider(Qt::Orientation orientation, QWidget* parent = nullptr);
};

#endif // SLIDER_H
