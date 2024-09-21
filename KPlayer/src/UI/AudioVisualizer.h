#ifndef AUDIOVISUALIZER_H
#define AUDIOVISUALIZER_H

#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QColor>

class AudioVisualizer : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Конструктор визуализатора
     * @param parent Родительский виджет
     */
    explicit AudioVisualizer(QWidget* parent = nullptr);

public slots:
    /**
     * @brief Обрабатывает аудио-буфер и обновляет визуализацию
     * @param buffer Аудио-данные
     */
    void processBuffer(const QByteArray& buffer);

    /**
     * @brief Обновляет анимацию
     */
    void updateAnimation();

protected:
    /**
     * @brief Рисует визуализацию
     * @param event Событие рисования
     */
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<QPointF> particlePositions; // Позиции частиц
    QVector<QPointF> particleVelocities; // Скорости частиц
    QVector<QColor> particleColors; // Цвета частиц
    const int maxParticles = 100;
    const int numParticles = 30; // Количество частиц
};

#endif // AUDIOVISUALIZER_H
