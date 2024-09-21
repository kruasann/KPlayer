// src/UI/AudioVisualizer.cpp

#include "AudioVisualizer.h"

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent)
{
    // �������������� ������ ������� �����
    levels.fill(0.0, 64); // ��������� ���������� ��������
}

void AudioVisualizer::processBuffer(const QAudioBuffer& buffer)
{
    levels.clear();

    // �������� ��������� �� ������ ������
    const qint16* data = buffer.constData<qint16>();
    int channelCount = buffer.format().channelCount();
    int sampleCount = buffer.sampleCount() / channelCount;

    // ������������ ������ �����
    for (int i = 0; i < sampleCount; i += channelCount) {
        qreal value = 0;
        // ��������� �������� �������
        for (int c = 0; c < channelCount; ++c) {
            value += qAbs(qreal(data[i + c])) / 32768.0;
        }
        value /= channelCount;
        levels.append(value);
    }

    // ������������ ���������� ������� ��� ������������
    const int maxLevels = 64;
    while (levels.size() > maxLevels) {
        levels.removeFirst();
    }

    // ��������� ������
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

        // ���� ������� �� ������ �����
        QColor color = QColor::fromHsvF(level, 1.0, 1.0);

        painter.fillRect(barRect, color);
    }
}
