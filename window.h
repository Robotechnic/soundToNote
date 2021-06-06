#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QChart>

#include <QAudioInput>
#include <QtEndian>

#include "soundChart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

using namespace QtCharts;

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
    SoundChart *chart;

    QAudioFormat format;
    QAudioInput *audio;
    void processAudioFrame(QByteArray data, int lenght);
};
#endif // WINDOW_H
