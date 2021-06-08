#ifndef SOUNDWIDGET_H
#define SOUNDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPolygonF>
#include <QTimer>

#include <QDebug>

class SoundWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SoundWidget(QWidget *parent = nullptr);
    ~ SoundWidget();

    void setBufferSize(int bufferSize);

public slots:
    void pushSoundLevel(double level);

private:
    void paintEvent(QPaintEvent *event);

    int bufferSize;
    QVector<float> buffer;
    QTimer *updateInterval;
};

#endif // SOUNDWIDGET_H
