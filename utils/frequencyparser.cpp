#include "utils/frequencyparser.h"

FrequencyParser::FrequencyParser(QObject *parent) : QThread(parent){}

FrequencyParser::~FrequencyParser(){
    this->quit();
    this->wait();
}

void FrequencyParser::pushAmplitude(const QVector<float> soundAmplitude){
    this->soundAmplitudeBuffer.append(soundAmplitude);
    if (!this->isRunning()){
        this->start();
    }
}

void FrequencyParser::clear() {
    this->notesBuffer.clear();
    this->soundAmplitudeBuffer.clear();
}

void FrequencyParser::run(){
    while (this->soundAmplitudeBuffer.size() > 0){
        this->procesAmplitude(this->soundAmplitudeBuffer.constFirst());
        this->soundAmplitudeBuffer.pop_back();
    }
}

void FrequencyParser::procesAmplitude(const QVector<float> soundAmplitude) {
    QDebug deb = qDebug();
    for (float f : soundAmplitude){
        deb<<f;
    }
}
