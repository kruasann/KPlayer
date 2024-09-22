#ifndef AUDIOVISUALIZER_H
#define AUDIOVISUALIZER_H

#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QColor>

/**
 * @class AudioVisualizer
 * @brief Виджет для визуализации аудио-данных с различными режимами отображения
 */
class AudioVisualizer : public QWidget {
    Q_OBJECT
public:
    // Типы визуализаций
    enum VisualizationType {
        Particles,     ///< Визуализация в виде частиц
        AbstractShapes ///< Визуализация абстрактных форм
    };

    explicit AudioVisualizer(QWidget* parent = nullptr);

    /**
     * @brief Устанавливает тип визуализации
     * @param type Тип визуализации (Particles, AbstractShapes)
     */
    void setVisualizationType(VisualizationType type);

public slots:
    /**
     * @brief Обрабатывает аудио-буфер и обновляет визуализацию
     * @param buffer Буфер с аудио-данными
     */
    void processBuffer(const QByteArray& buffer);

    /**
     * @brief Обновляет анимацию (вызывается таймером)
     */
    void updateAnimation();

protected:
    /**
     * @brief Событие рисования виджета
     * @param event Событие рисования
     */
    void paintEvent(QPaintEvent* event) override;

private:
    // Методы обновления анимаций для разных типов визуализации
    void updateParticles();
    void updateAbstractShapes(); // Для абстрактных форм

    // Методы рисования разных типов визуализаций
    void paintParticles(QPainter& painter);
    void paintAbstractShapes(QPainter& painter); // Для абстрактных форм

    QVector<QPointF> particlePositions;  // Позиции частиц
    QVector<QPointF> particleVelocities; // Скорости частиц
    QVector<QColor> particleColors;      // Цвета частиц

    QVector<QPointF> controlPoints;      // Контрольные точки для абстрактных форм
    QVector<QPointF> nextControlPoints;  // Следующие контрольные точки для плавного перехода
    QColor gradientStartColor;           // Начальный цвет градиента
    QColor gradientEndColor;             // Конечный цвет градиента
    QColor currentGradientColor;         // Текущий цвет градиента в процессе перехода
    qreal transitionStep;                // Шаг для плавного перехода между контрольными точками

    const int numParticles = 30;         // Текущее количество частиц
    const int numShapes = 5;             // Количество контрольных точек для абстрактных форм

    VisualizationType currentType;       ///< Текущий выбранный тип визуализации
};

#endif // AUDIOVISUALIZER_H