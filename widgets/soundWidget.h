#ifndef SOUNDWIDGET_H
#define SOUNDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QPolygonF>
#include <QTimer>

#include <QDebug>

class SoundWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SoundWidget(QWidget *parent = nullptr);
    ~ SoundWidget();

    void pushSoundLevel(double level);
    void pushSoundLevel(QVector<double> level);

    void setFramePerMs(int frames){this->framePerMs = frames;};

private:
    void paintEvent(QPaintEvent *event);

    int bufferSize;
    int framePerMs;
    QVector<double> buffer;
    QTimer *updateInterval;
};

#endif // SOUNDWIDGET_H
