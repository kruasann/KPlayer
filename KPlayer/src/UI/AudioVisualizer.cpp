// src/UI/AudioVisualizer.cpp

#include "AudioVisualizer.h"
#include <QAudioFormat>
#include <QPainter>

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent)
{
}

void AudioVisualizer::processBuffer(const QByteArray& buffer)
{
    levels.clear();

    const qint16* data = reinterpret_cast<const qint16*>(buffer.constData());
    int sampleCount = buffer.size() / sizeof(qint16);

    // Обрабатываем каждый семпл
    for (int i = 0; i < sampleCount; ++i) {
        qreal value = qAbs(qreal(data[i])) / 32768.0;
        levels.append(value);
    }

    // Ограничиваем количество уровней для визуализации
    const int maxLevels = 64;
    while (levels.size() > maxLevels) {
        levels.removeFirst();
    }

    // Обновляем виджет
    update();
}

void AudioVisualizer::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    if (levels.isEmpty())
        return;

    int barWidth = width() / levels.size();
    for (int i = 0; i < levels.size(); ++i) {
        qreal level = levels[i];
        int barHeight = static_cast<int>(level * height());
        QRect barRect(i * barWidth, height() - barHeight, barWidth, barHeight);

        // Цвет зависит от уровня звука
        QColor color = QColor::fromHsvF(level, 1.0, 1.0);

        painter.fillRect(barRect, color);
    }
}
