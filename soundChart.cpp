#include "soundChart.h"

SoundChart::SoundChart(QGraphicsItem *parent, Qt::WindowFlags wFlags) :
    QChart(parent,wFlags),
    xAxis(new QValueAxis()),
    yAxis(new QValueAxis()),
    bufferSize(2000)
{
    //setpu spline
    soundLevel = new QLineSeries(this);
    QPen p(Qt::red);
    p.setWidth(1);
    soundLevel->setPen(p);
    this->addSeries(soundLevel);

    //setup axis
    this->addAxis(this->xAxis,Qt::AlignBottom);
    this->addAxis(this->yAxis,Qt::AlignLeft);
    soundLevel->attachAxis(this->xAxis);
    soundLevel->attachAxis(this->yAxis);

    xAxis->setRange(0,bufferSize);
    yAxis->setRange(-2,2);

    for (int i = 0; i<bufferSize; i++){
        buffer.push_back(QPointF(i,0));
    }
}

SoundChart::~SoundChart(){}

void SoundChart::setBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
    buffer.clear();
    for (int i = 0; i<bufferSize; i++){
        buffer.push_back(QPointF(i,0));
    }
    xAxis->setRange(0,bufferSize);
}

void SoundChart::pushSoundLevel(double level){

    for (int i = 0; i<bufferSize-1; i++){
        buffer[i].setY(buffer.at(i+1).y());
    }

    buffer.last().setY(level);

    this->soundLevel->replace(buffer);
}
