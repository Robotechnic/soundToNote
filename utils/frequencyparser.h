#ifndef FREQUENCYPARSER_H
#define FREQUENCYPARSER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "notesFrequency.h"


class FrequencyParser : public QThread
{
    Q_OBJECT
public:
    FrequencyParser(QObject *parent = nullptr);
    ~ FrequencyParser();
    void pushAmplitude(const QVector<float> soundAmplitude);
    void clear();

signals:
    void newFrequencyProcessed(Note note);

private:
    QVector<QVector<float>> soundAmplitudeBuffer;
    QVector<Note> notesBuffer;

    void run() override;

    void procesAmplitude(const QVector<float> soundAmplitude);
};

#endif // FREQUENCYPARSER_H
