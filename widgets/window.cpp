#include "window.h"
#include "ui_window.h"



Window::Window(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Window),
      audioBuffer(this)
{
    ui->setupUi(this);

    //setup audio input
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setSampleType(QAudioFormat::SignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setCodec("audio/pcm");

    //setup audio input
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
        qDebug()<<format;
    }

    audio = new QAudioInput(format,this);
    connect(audio,&QAudioInput::stateChanged,this,&Window::stateManager);

    audio->setNotifyInterval(75); //75 ms is the duration of a quarter at 100bpm

    connect(audio,&QAudioInput::notify,[this]{
        int ready = audio->bytesReady();
        this->audioBuffer.seek(0);
        qDebug()<<format.durationForBytes(this->audioBuffer.bytesAvailable())/1000;
        this->processAudioFrame(this->audioBuffer.read(ready));
        this->audioBuffer.buffer().clear();
        this->audioBuffer.seek(0);
    });
}

Window::~Window()
{
    this->on_stopRecording_clicked();
    delete ui;
}

void Window::stateManager(QAudio::State newState) {
    qDebug()<<newState;
}

void Window::on_startRecording_clicked()
{
    qDebug()<<"Start recording";
    this->audioBuffer.open(QIODevice::ReadWrite);
    this->audio->start(&this->audioBuffer);
}

void Window::processAudioFrame(QByteArray data){
    const short* frames = (short *)data.constData();


//    qDebug()<< data.length() << format.durationForBytes(data.length())/1000.0 << this->audio->notifyInterval();
    for (int  i=0; i < data.length()/2; i ++ ){
        ui->soundView->pushSoundLevel(frames[i]);
    }
}

void Window::on_stopRecording_clicked()
{
    qDebug()<<"Stop recording";
    this->audio->stop();
    this->audioBuffer.close();
}
