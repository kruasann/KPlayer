#include "AudioVisualizer.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QColor>
#include <QLinearGradient>
#include <QDebug>
#include <QPainterPath>

/**
 * @brief ������������ ����� ����� �������
 * @param startColor ��������� ����
 * @param endColor �������� ����
 * @param t ����������� ������������ [0, 1]
 * @return ����������������� ����
 */
QColor interpolateColor(const QColor& startColor, const QColor& endColor, qreal t) {
    int red = static_cast<int>(startColor.red() + t * (endColor.red() - startColor.red()));
    int green = static_cast<int>(startColor.green() + t * (endColor.green() - startColor.green()));
    int blue = static_cast<int>(startColor.blue() + t * (endColor.blue() - startColor.blue()));
    return QColor(red, green, blue);
}

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent), currentType(AbstractShapes), transitionStep(0)  // ��������� ��� ������������ "AbstractShapes"
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AudioVisualizer::updateAnimation);
    timer->start(30); // ������� ����������

    // ������������� ��������� ����� ��� ����������� ����
    for (int i = 0; i < numShapes; ++i) {
        controlPoints.append(QPointF(
            QRandomGenerator::global()->bounded(width()),
            QRandomGenerator::global()->bounded(height())
        ));
        nextControlPoints.append(QPointF( // ��������� ������������� nextControlPoints
            QRandomGenerator::global()->bounded(width()),
            QRandomGenerator::global()->bounded(height())
        ));
    }

    // ��������� ����� ���������
    gradientStartColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
    gradientEndColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
}


/**
 * @brief ������������� ��� ������������
 * @param type ��� ������������ (Particles, AbstractShapes)
 */
void AudioVisualizer::setVisualizationType(VisualizationType type) {
    currentType = type; // ��������� ��� ������������
    update();           // �������������� ������
}

void AudioVisualizer::processBuffer(const QByteArray& buffer) {
    Q_UNUSED(buffer);
    // ���� ��� �� ����������� � �����-������
}

/**
 * @brief ��������� �������� � ����������� �� �������� ���� ������������
 */
void AudioVisualizer::updateAnimation() {
    switch (currentType) {
    case Particles:
        updateParticles();  // ���������� ������
        break;
    case AbstractShapes:
        updateAbstractShapes(); // ���������� ����������� ����
        break;
    }
    update(); // ������ �� �����������
}

/**
 * @brief ��������� ������� � ����� ������
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
 * @brief ���������� ����������� ���� � �������� ����������
 */
void AudioVisualizer::updateAbstractShapes() {
    if (controlPoints.size() != nextControlPoints.size()) {
        qDebug() << "������: ����������� ����� � ��������� ����������� ����� ����� ������ ������.";
        return;
    }

    // ������� ��������� ����� ����������� �����
    transitionStep += 0.02; // ������� ������� �� ���� ��������� �����

    if (transitionStep >= 1.0) {
        transitionStep = 0.0;
        // ����� ����������� ����, ���������� ����� ����������� ����� � �����
        for (int i = 0; i < numShapes; ++i) {
            nextControlPoints[i] = QPointF(
                QRandomGenerator::global()->bounded(width()),
                QRandomGenerator::global()->bounded(height())
            );
        }
        gradientStartColor = gradientEndColor;
        gradientEndColor = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
    }

    // ������������� ������� ����������� ����� � �����
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
 * @brief ��������� ������� ����������� ���� � �����������
 */
void AudioVisualizer::paintAbstractShapes(QPainter& painter) {
    painter.fillRect(rect(), Qt::black);

    // ������� ���� ��� ������� ������
    QPainterPath path;
    path.moveTo(controlPoints[0]);

    for (int i = 1; i < controlPoints.size(); ++i) {
        qreal x1 = controlPoints[i - 1].x();
        qreal y1 = controlPoints[i - 1].y();
        qreal x2 = controlPoints[i].x();
        qreal y2 = controlPoints[i].y();
        path.quadTo(QPointF(x1, y1), QPointF(x2, y2));
    }

    // ������� �������� ����� ����� �������
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(0, currentGradientColor);
    gradient.setColorAt(1, QColor(0, 0, 0));

    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    painter.drawPath(path);
}