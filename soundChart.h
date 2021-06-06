#ifndef SOUNDCHART_H
#define SOUNDCHART_H

#include <QtCharts>
#include <QtCharts/QChart>
#include <QXYSeries>
#include <QDebug>

using namespace QtCharts;

class SoundChart : public QChart
{
    Q_OBJECT
public:
    explicit SoundChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    ~ SoundChart();

    void setBufferSize(int bufferSize);

public slots:
    void pushSoundLevel(double level);

private:

    QValueAxis *xAxis,*yAxis;
    int x;

    int bufferSize;
    QVector<QPointF> buffer;
    QLineSeries *soundLevel;

};

#endif // SOUNDCHART_H
