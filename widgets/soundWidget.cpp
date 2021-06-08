#include "soundWidget.h"

SoundWidget::SoundWidget(QWidget *parent) :
    QWidget(parent),
    updateInterval(new QTimer(this))
{
    this->setBufferSize(1000);
    updateInterval->setInterval(100);
    connect(updateInterval,&QTimer::timeout,this,QOverload<>::of(&SoundWidget::update));
    updateInterval->start();
}

SoundWidget::~SoundWidget(){}

void SoundWidget::setBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
    buffer.clear();
    for (int i = 0; i<bufferSize; i++){
        buffer.push_back(0);
    }
    this->update();
}

void SoundWidget::pushSoundLevel(double level){
    buffer.push_back(level);
    buffer.pop_front();
}


void SoundWidget::paintEvent(QPaintEvent *event){
    QPainter p(this);
    QPolygonF soundWave;

    for (int x = 0; x<this->bufferSize; x++){
        soundWave<<QPointF(x,(buffer.at(x)/65534.0*this->height()*0.5)+this->height()/2);
    }

    p.drawPolyline(soundWave);
}
