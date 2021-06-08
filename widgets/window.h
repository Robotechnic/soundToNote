#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QAudioInput>
#include <QBuffer>

#include <QDebug>

#include "soundWidget.h"

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
    void on_startRecording_clicked();

    void on_stopRecording_clicked();

    void stateManager(QAudio::State newState);

private:
    Ui::Window *ui;

    QAudioFormat format;
    QAudioInput *audio;
    QBuffer audioBuffer;
    void processAudioFrame(QByteArray data);
};
#endif // WINDOW_H
