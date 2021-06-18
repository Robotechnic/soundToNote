#include "widgets/soundWidget.h"

SoundWidget::SoundWidget(QWidget *parent) :
    QWidget(parent),
    buffer(this->width(),0),
    updateInterval(new QTimer(this))
{
    updateInterval->setInterval(100);



    connect(updateInterval,&QTimer::timeout,[this]{
        for (int i = 0; i < this->framePerMs * 100 && this->buffer.size() > this->width(); i++){
            this->buffer.pop_front();
        }
        this->update();
    });

    updateInterval->start();
}

SoundWidget::~SoundWidget(){}


void SoundWidget::pushSoundLevel(double level){
    buffer.push_back(level);
    buffer.pop_front();
}

void SoundWidget::pushSoundLevel(QVector<double> level) {
    this->buffer.append(level);
}

void SoundWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    QPolygonF soundWave;

    for (int x = 0; x<qMin(this->width(),this->buffer.size()); x++){
        soundWave<<QPointF(x,(buffer.at(x)/65534.0*this->height()*0.6)+this->height()/2);
    }

    p.fillRect(this->rect(),QColor(0x28,0x29,0x23));

    p.setPen(Qt::white);
    p.drawLine(0,this->height()/2,this->width(),this->height()/2);

    QPainterPath path;
    path.moveTo(this->width(),this->height()/2);
    path.lineTo(this->width()-5,this->height()/2-5);
    path.lineTo(this->width()-5,this->height()/2+5);
    p.fillPath(path,Qt::white);

    p.setPen(Qt::blue);
    p.drawPolyline(soundWave);

}
