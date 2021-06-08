#ifndef FREQUENCYPARSER_H
#define FREQUENCYPARSER_H

#include <QObject>

class FrequencyParser
{
    Q_OBJECT
public:


signals:
    void newNoteReady();

public:
    FrequencyParser();
};

#endif // FREQUENCYPARSER_H
