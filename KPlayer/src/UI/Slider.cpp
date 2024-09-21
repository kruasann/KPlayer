// src/UI/Slider.cpp
#include "Slider.h"

Slider::Slider(Qt::Orientation orientation, QWidget* parent) : QSlider(orientation, parent) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
