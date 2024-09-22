#ifndef AUDIOVISUALIZER_H
#define AUDIOVISUALIZER_H

#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QColor>

/**
 * @class AudioVisualizer
 * @brief ������ ��� ������������ �����-������ � ���������� �������� �����������
 */
class AudioVisualizer : public QWidget {
    Q_OBJECT
public:
    // ���� ������������
    enum VisualizationType {
        Particles,     ///< ������������ � ���� ������
        AbstractShapes ///< ������������ ����������� ����
    };

    explicit AudioVisualizer(QWidget* parent = nullptr);

    /**
     * @brief ������������� ��� ������������
     * @param type ��� ������������ (Particles, AbstractShapes)
     */
    void setVisualizationType(VisualizationType type);

public slots:
    /**
     * @brief ������������ �����-����� � ��������� ������������
     * @param buffer ����� � �����-�������
     */
    void processBuffer(const QByteArray& buffer);

    /**
     * @brief ��������� �������� (���������� ��������)
     */
    void updateAnimation();

protected:
    /**
     * @brief ������� ��������� �������
     * @param event ������� ���������
     */
    void paintEvent(QPaintEvent* event) override;

private:
    // ������ ���������� �������� ��� ������ ����� ������������
    void updateParticles();
    void updateAbstractShapes(); // ��� ����������� ����

    // ������ ��������� ������ ����� ������������
    void paintParticles(QPainter& painter);
    void paintAbstractShapes(QPainter& painter); // ��� ����������� ����

    QVector<QPointF> particlePositions;  // ������� ������
    QVector<QPointF> particleVelocities; // �������� ������
    QVector<QColor> particleColors;      // ����� ������

    QVector<QPointF> controlPoints;      // ����������� ����� ��� ����������� ����
    QVector<QPointF> nextControlPoints;  // ��������� ����������� ����� ��� �������� ��������
    QColor gradientStartColor;           // ��������� ���� ���������
    QColor gradientEndColor;             // �������� ���� ���������
    QColor currentGradientColor;         // ������� ���� ��������� � �������� ��������
    qreal transitionStep;                // ��� ��� �������� �������� ����� ������������ �������

    const int numParticles = 30;         // ������� ���������� ������
    const int numShapes = 5;             // ���������� ����������� ����� ��� ����������� ����

    VisualizationType currentType;       ///< ������� ��������� ��� ������������
};

#endif // AUDIOVISUALIZER_H