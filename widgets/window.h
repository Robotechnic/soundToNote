#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QAudioInput>
#include <QBuffer>

#include <QDebug>

#include "soundWidget.h"
#include "utils/frequencyparser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void start();

    void stop(bool clear = false);

    void stateManager(QAudio::State newState);

    void on_actionStartRecording_triggered();

    void on_actionStopRecording_triggered();

    void on_actionPauseRecording_triggered();


private:
    Ui::Window *ui;

    QAudioFormat format;
    QAudioInput *audio;
    int maxFrameSize;
    QBuffer audioBuffer;
    void processAudioFrame(QByteArray data);

    void setRecordUIState(bool recording);

    FrequencyParser parser;
};
#endif // WINDOW_H
