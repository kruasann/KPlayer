#include "AudioVisualizer.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QColor>
#include <QLinearGradient>
#include <QDebug>
#include <QPainterPath>

/**
 * @brief Интерполяция между двумя цветами
 * @param startColor Начальный цвет
 * @param endColor Конечный цвет
 * @param t Коэффициент интерполяции [0, 1]
 * @return Интерполированный цвет
 */
QColor interpolateColor(const QColor& startColor, const QColor& endColor, qreal t) {
    int red = static_cast<int>(startColor.red() + t * (endColor.red() - startColor.red()));
    int green = static_cast<int>(startColor.green() + t * (endColor.green() - startColor.green()));
    int blue = static_cast<int>(startColor.blue() + t * (endColor.blue() - startColor.blue()));
    return QColor(red, green, blue);
}

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent), currentType(AbstractShapes), transitionStep(0)  // Начальный тип визуализации "AbstractShapes"
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AudioVisualizer::updateAnimation);
    timer->start(30); // Частота обновления

    // Инициализация начальных точек для абстрактных форм
    for (int i = 0; i < numShapes; ++i) {
        controlPoints.append(QPointF(
            QRandomGenerator::global()->bounded(width()),
            QRandomGenerator::global()->bounded(height())
        ));
        nextControlPoints.append(QPointF( // Добавляем инициализацию nextControlPoints
            QRandomGenerator::global()->bounded(width()),
            QRandomGenerator::global()->bounded(height())
        ));
    }

    // Начальные цвета градиента
    gradientStartColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
    gradientEndColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
}


/**
 * @brief Устанавливает тип визуализации
 * @param type Тип визуализации (Particles, AbstractShapes)
 */
void AudioVisualizer::setVisualizationType(VisualizationType type) {
    currentType = type; // Обновляем тип визуализации
    update();           // Перерисовываем виджет
}

void AudioVisualizer::processBuffer(const QByteArray& buffer) {
    Q_UNUSED(buffer);
    // Пока что не привязываем к аудио-данным
}

/**
 * @brief Обновляет анимацию в зависимости от текущего типа визуализации
 */
void AudioVisualizer::updateAnimation() {
    switch (currentType) {
    case Particles:
        updateParticles();  // Обновление частиц
        break;
    case AbstractShapes:
        updateAbstractShapes(); // Обновление абстрактных форм
        break;
    }
    update(); // Запрос на перерисовку
}

/**
 * @brief Обновляет позиции и цвета частиц
 */
void AudioVisualizer::updateParticles() {
    for (int i = 0; i < numParticles; ++i) {
        particlePositions[i] += particleVelocities[i];
        if (particlePositions[i].x() < 0 || particlePositions[i].x() > width()) {
            particleVelocities[i].setX(-particleVelocities[i].x());
        }
        if (particlePositions[i].y() < 0 || particlePositions[i].y() > height()) {
            particleVelocities[i].setY(-particleVelocities[i].y());
        }
        particleColors[i].setHsv((particleColors[i].hue() + 1) % 360, 255, 255);
    }
}

/**
 * @brief Обновление абстрактных форм с плавными переходами
 */
void AudioVisualizer::updateAbstractShapes() {
    if (controlPoints.size() != nextControlPoints.size()) {
        qDebug() << "Ошибка: контрольные точки и следующие контрольные точки имеют разный размер.";
        return;
    }

    // Плавное изменение точек контрольных точек
    transitionStep += 0.02; // Плавный переход за счет маленьких шагов

    if (transitionStep >= 1.0) {
        transitionStep = 0.0;
        // Когда завершается цикл, генерируем новые контрольные точки и цвета
        for (int i = 0; i < numShapes; ++i) {
            nextControlPoints[i] = QPointF(
                QRandomGenerator::global()->bounded(width()),
                QRandomGenerator::global()->bounded(height())
            );
        }
        gradientStartColor = gradientEndColor;
        gradientEndColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
    }

    // Интерполируем текущие контрольные точки и цвета
    for (int i = 0; i < controlPoints.size(); ++i) {
        controlPoints[i] = controlPoints[i] * (1 - transitionStep) + nextControlPoints[i] * transitionStep;
    }

    currentGradientColor = interpolateColor(gradientStartColor, gradientEndColor, transitionStep);
}


void AudioVisualizer::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (currentType) {
    case Particles:
        paintParticles(painter);
        break;
    case AbstractShapes:
        paintAbstractShapes(painter);
        break;
    }
}

void AudioVisualizer::paintParticles(QPainter& painter) {
    painter.fillRect(rect(), Qt::black);
    for (int i = 0; i < numParticles; ++i) {
        QRadialGradient gradient(particlePositions[i], 50);
        gradient.setColorAt(0, particleColors[i]);
        gradient.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(particlePositions[i], 50, 50);
    }
}


/**
 * @brief Рисование плавных абстрактных форм с градиентами
 */
void AudioVisualizer::paintAbstractShapes(QPainter& painter) {
    painter.fillRect(rect(), Qt::black);

    // Создаем путь для плавных кривых
    QPainterPath path;
    path.moveTo(controlPoints[0]);

    for (int i = 1; i < controlPoints.size(); ++i) {
        qreal x1 = controlPoints[i - 1].x();
        qreal y1 = controlPoints[i - 1].y();
        qreal x2 = controlPoints[i].x();
        qreal y2 = controlPoints[i].y();
        path.quadTo(QPointF(x1, y1), QPointF(x2, y2));
    }

    // Плавный градиент между двумя цветами
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(0, currentGradientColor);
    gradient.setColorAt(1, QColor(0, 0, 0));

    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    painter.drawPath(path);
}