#include "AudioVisualizer.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QColor>
#include <QLinearGradient>
#include <QDebug> // Опционально для отладки

AudioVisualizer::AudioVisualizer(QWidget* parent)
    : QWidget(parent)
{
    // Инициализация таймера для анимации
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AudioVisualizer::updateAnimation);
    timer->start(30); // обновляем анимацию каждые 30 миллисекунд

    // Инициализируем случайные позиции и параметры для "дымков"
    for (int i = 0; i < numParticles; ++i) {
        // Генерация случайной позиции (целые числа)
        int randX = QRandomGenerator::global()->bounded(width());   // Версия для int
        int randY = QRandomGenerator::global()->bounded(height());  // Версия для int

        particlePositions.append(QPointF(
            static_cast<qreal>(randX),
            static_cast<qreal>(randY)
        ));

        // Генерация случайной скорости (числа с плавающей точкой)
        double randVX = QRandomGenerator::global()->generateDouble() * 2.0 - 1.0; // Диапазон [-1.0, 1.0)
        double randVY = QRandomGenerator::global()->generateDouble() * 2.0 - 1.0; // Диапазон [-1.0, 1.0)

        particleVelocities.append(QPointF(
            static_cast<qreal>(randVX),
            static_cast<qreal>(randVY)
        ));

        // Генерация случайного оттенка цвета
        int randHue = QRandomGenerator::global()->bounded(360); // Версия для int

        particleColors.append(QColor::fromHsv(
            randHue, 255, 255 // Полная насыщенность и яркость
        ));

        // (Опционально) Отладочные сообщения для проверки значений
        // qDebug() << "Particle" << i << ": pos=(" << randX << "," << randY << "), vel=(" << randVX << "," << randVY << "), hue=" << randHue;
    }
}

void AudioVisualizer::processBuffer(const QByteArray& buffer)
{
    // Если визуализация не зависит от аудио-данных, оставь функцию пустой
    Q_UNUSED(buffer);

    // Если хочешь использовать аудио-данные для влияния на визуализацию, реализуй логику здесь
    // Пример: изменять количество частиц в зависимости от уровня громкости
    qint64 sum = 0;
    for (char byte : buffer) {
        sum += static_cast<unsigned char>(byte);
    }
    double average = static_cast<double>(sum) / buffer.size();
    int newParticleCount = static_cast<int>((average / 255.0) * maxParticles);

    // Логика добавления или удаления частиц
}

void AudioVisualizer::updateAnimation()
{
    // Обновляем позиции и цвета для частиц
    for (int i = 0; i < numParticles; ++i) {
        particlePositions[i] += particleVelocities[i];

        // Отражение от краев виджета
        if (particlePositions[i].x() < 0 || particlePositions[i].x() > width()) {
            particleVelocities[i].setX(-particleVelocities[i].x());
        }
        if (particlePositions[i].y() < 0 || particlePositions[i].y() > height()) {
            particleVelocities[i].setY(-particleVelocities[i].y());
        }

        // Плавное изменение цвета
        int hue = particleColors[i].hue();
        hue = (hue + 1) % 360; // изменяем цвет плавно
        particleColors[i].setHsv(hue, 255, 255);
    }

    // Обновляем виджет
    update();
}

void AudioVisualizer::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::black); // заполняем черный фон

    // Рисуем "дымки"
    for (int i = 0; i < numParticles; ++i) {
        QColor color = particleColors[i];
        QPointF position = particlePositions[i];

        // Рисуем плавные круги, которые постепенно изменяются по размеру
        QRadialGradient gradient(position, 50);
        gradient.setColorAt(0, color);
        gradient.setColorAt(1, QColor(0, 0, 0, 0)); // Прозрачный край

        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);

        painter.drawEllipse(position, 50, 50); // Рисуем круг
    }
}
