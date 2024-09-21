// src/UI/AudioVisualizer.h

#ifndef AUDIOVISUALIZER_H
#define AUDIOVISUALIZER_H

#include <QWidget>
#include <QByteArray>
#include <QPainter>
#include <QVector>

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

protected:
    /**
     * @brief Рисует визуализацию
     * @param event Событие рисования
     */
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<qreal> levels;
};

#endif // AUDIOVISUALIZER_H
