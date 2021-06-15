#ifndef FREQUENCYPARSER_H
#define FREQUENCYPARSER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <complex>

#include "notesFrequency.h"
#include "fft.h"


class FrequencyParser : public QThread
{
    Q_OBJECT
public:
    FrequencyParser(QObject *parent = nullptr, int frequency = 16000);
    ~ FrequencyParser();
    void pushAmplitude(const QVector<double> soundAmplitude);
    void clear();

signals:
    void newFrequencyProcessed(Note note);

private:
    QVector<QVector<double>> soundAmplitudeBuffer;
    QVector<Note> notesBuffer;

    void run() override;

    int frequency;
    double procesAmplitude(const QVector<double> soundAmplitude);
    octave nearestNote(double freq);
};

#endif // FREQUENCYPARSER_H
