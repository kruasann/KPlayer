#include "AudioVisualizer.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QColor>
#include <QLinearGradient>
#include <QDebug> // ����������� ��� �������

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent)
{
    // ������������� ������� ��� ��������
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AudioVisualizer::updateAnimation);
    timer->start(30); // ��������� �������� ������ 30 �����������

    // �������������� ��������� ������� � ��������� ��� "������"
    for (int i = 0; i < numParticles; ++i) {
        // ��������� ��������� ������� (����� �����)
        int randX = QRandomGenerator::global()->bounded(width());   // ������ ��� int
        int randY = QRandomGenerator::global()->bounded(height());  // ������ ��� int

        particlePositions.append(QPointF(
            static_cast<qreal>(randX),
            static_cast<qreal>(randY)
        ));

        // ��������� ��������� �������� (����� � ��������� ������)
        double randVX = QRandomGenerator::global()->generateDouble() * 2.0 - 1.0; // �������� [-1.0, 1.0)
        double randVY = QRandomGenerator::global()->generateDouble() * 2.0 - 1.0; // �������� [-1.0, 1.0)

        particleVelocities.append(QPointF(
            static_cast<qreal>(randVX),
            static_cast<qreal>(randVY)
        ));

        // ��������� ���������� ������� �����
        int randHue = QRandomGenerator::global()->bounded(360); // ������ ��� int

        particleColors.append(QColor::fromHsv(
            randHue, 255, 255 // ������ ������������ � �������
        ));

        // (�����������) ���������� ��������� ��� �������� ��������
        // qDebug() << "Particle" << i << ": pos=(" << randX << "," << randY << "), vel=(" << randVX << "," << randVY << "), hue=" << randHue;
    }
}

void AudioVisualizer::processBuffer(const QByteArray& buffer)
{
    // ���� ������������ �� ������� �� �����-������, ������ ������� ������
    Q_UNUSED(buffer);

    // ���� ������ ������������ �����-������ ��� ������� �� ������������, �������� ������ �����
    // ������: �������� ���������� ������ � ����������� �� ������ ���������
    qint64 sum = 0;
    for (char byte : buffer) {
        sum += static_cast<unsigned char>(byte);
    }
    double average = static_cast<double>(sum) / buffer.size();
    int newParticleCount = static_cast<int>((average / 255.0) * maxParticles);

    // ������ ���������� ��� �������� ������
}

void AudioVisualizer::updateAnimation()
{
    // ��������� ������� � ����� ��� ������
    for (int i = 0; i < numParticles; ++i) {
        particlePositions[i] += particleVelocities[i];

        // ��������� �� ����� �������
        if (particlePositions[i].x() < 0 || particlePositions[i].x() > width()) {
            particleVelocities[i].setX(-particleVelocities[i].x());
        }
        if (particlePositions[i].y() < 0 || particlePositions[i].y() > height()) {
            particleVelocities[i].setY(-particleVelocities[i].y());
        }

        // ������� ��������� �����
        int hue = particleColors[i].hue();
        hue = (hue + 1) % 360; // �������� ���� ������
        particleColors[i].setHsv(hue, 255, 255);
    }

    // ��������� ������
    update();
}

void AudioVisualizer::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::black); // ��������� ������ ���

    // ������ "�����"
    for (int i = 0; i < numParticles; ++i) {
        QColor color = particleColors[i];
        QPointF position = particlePositions[i];

        // ������ ������� �����, ������� ���������� ���������� �� �������
        QRadialGradient gradient(position, 50);
        gradient.setColorAt(0, color);
        gradient.setColorAt(1, QColor(0, 0, 0, 0)); // ���������� ����

        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);

        painter.drawEllipse(position, 50, 50); // ������ ����
    }
}
