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
     * @brief ����������� ������������� �����
     * @param parent ������������ ������
     */
    explicit AudioVisualizer(QWidget* parent = nullptr);

public slots:
    /**
     * @brief ������������ �����-����� ��� ������������
     * @param buffer �����-�����
     */
    void processBuffer(const QAudioBuffer& buffer);

protected:
    /**
     * @brief ������ ������������
     * @param event ������� ���������
     */
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<qreal> levels; ///< ������ ����� ��� ������������
};

#endif // AUDIOVISUALIZER_H
