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
     * @brief ����������� �������������
     * @param parent ������������ ������
     */
    explicit AudioVisualizer(QWidget* parent = nullptr);

public slots:
    /**
     * @brief ������������ �����-����� � ��������� ������������
     * @param buffer �����-������
     */
    void processBuffer(const QByteArray& buffer);

    /**
     * @brief ��������� ��������
     */
    void updateAnimation();

protected:
    /**
     * @brief ������ ������������
     * @param event ������� ���������
     */
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<QPointF> particlePositions; // ������� ������
    QVector<QPointF> particleVelocities; // �������� ������
    QVector<QColor> particleColors; // ����� ������
    const int maxParticles = 100;
    const int numParticles = 30; // ���������� ������
};

#endif // AUDIOVISUALIZER_H
