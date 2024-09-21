// src/UI/AudioVisualizer.h

#ifndef AUDIOVISUALIZER_H
#define AUDIOVISUALIZER_H

#include <QWidget>
#include <QAudioBuffer>
#include <QPainter>

class AudioVisualizer : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Конструктор визуализатора звука
     * @param parent Родительский виджет
     */
    explicit AudioVisualizer(QWidget* parent = nullptr);

public slots:
    /**
     * @brief Обрабатывает аудио-буфер для визуализации
     * @param buffer Аудио-буфер
     */
    void processBuffer(const QAudioBuffer& buffer);

protected:
    /**
     * @brief Рисует визуализацию
     * @param event Событие рисования
     */
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<qreal> levels; ///< Уровни звука для визуализации
};

#endif // AUDIOVISUALIZER_H
