#include "utils/frequencyparser.h"

FrequencyParser::FrequencyParser(QObject *parent, int frequency) : QThread(parent), frequency(frequency){}

FrequencyParser::~FrequencyParser(){
    this->quit();
    this->wait();
}

void FrequencyParser::pushAmplitude(const QVector<double> soundAmplitude){
    this->soundAmplitudeBuffer.append(soundAmplitude);
    if (!this->isRunning()){
        this->start();
    }
}

void FrequencyParser::clear() {
    this->quit();
    this->wait();
    this->notesBuffer.clear();
    this->soundAmplitudeBuffer.clear();
}

void FrequencyParser::run(){
    while (this->soundAmplitudeBuffer.size() > 0){
        double freq =  this->procesAmplitude(this->soundAmplitudeBuffer.constFirst());
        octave note = nearestNote(freq);

        if (this->notesBuffer.size() > 0 && this->notesBuffer.last().note == note && this->notesBuffer.last().type != breve){
            this->notesBuffer.last().type = static_cast<noteDuration>(this->notesBuffer.last().type + 1);
        } else {
            this->notesBuffer.append(Note(breve,note));
        }

        emit newFrequencyProcessed(Note(breve,note));

        this->soundAmplitudeBuffer.pop_back();
    }
}

double FrequencyParser::procesAmplitude(const QVector<double> soundAmplitude) {
    QVector <std::complex<double>> result;

    //compute fft
    fft(soundAmplitude,result,soundAmplitude.length());

    int maxId = 0;
    double amplitude = 0, maxAmplitude = 0;

    //get max amplitude
    for (int i = 0; i<result.length()/2; i++){
        amplitude = sqrt(pow(result.at(i).real(),2)),pow(result.at(i).imag(),2);
        if (maxAmplitude < amplitude){
            maxAmplitude = amplitude;
            maxId = i;
        }
    }

    //get frequency of amplitude
    if (maxAmplitude > 1e6){
        double freq = maxId * frequency / soundAmplitude.size();
        return freq;
    } else {
        return 0;
    }
}

octave FrequencyParser::nearestNote(double freq) {
    double minDiff = 100,diff = 0;
    octave result;

    for (octave o : octaves){
        diff = abs( (o / 100) - freq);
        if (diff < minDiff){
            minDiff = diff;
            result = o;
        }
    }
    return result;
}
