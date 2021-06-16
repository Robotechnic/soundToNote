#include "widgets/window.h"
#include "ui_window.h"

#define SAMPLE_RATE 35000
#define MIN_NOTE_DURATION 75 //75 ms is the duration of a quarter at 100bpm


Window::Window(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Window),
      audioBuffer(this),
      parser(this,SAMPLE_RATE)
{
    ui->setupUi(this);

    //setup audio input
    format.setSampleRate(SAMPLE_RATE);
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

    audio->setNotifyInterval(MIN_NOTE_DURATION);
    maxFrameSize = format.bytesForDuration(MIN_NOTE_DURATION*1000);


    connect(audio,&QAudioInput::notify,[this]{
        int ready = qMin(audio->bytesReady(),maxFrameSize);

        this->audioBuffer.seek(0);
        this->processAudioFrame(this->audioBuffer.read(ready));
        this->audioBuffer.buffer().clear();
        this->audioBuffer.seek(0);
    });

    //setup sound widget
    //ui->soundView->setFrameDuration(MIN_NOTE_DURATION/maxFrameSize);
}

Window::~Window() {
    this->stop();
    delete ui;
}

void Window::stateManager(QAudio::State newState) {
    qDebug()<<newState;
    this->setRecordUIState(newState != QAudio::State::StoppedState);
}

void Window::start(){
    qDebug()<<"Start recording";
    this->audioBuffer.open(QIODevice::ReadWrite);
    this->audio->start(&this->audioBuffer);
}

void Window::processAudioFrame(QByteArray data){
    const short* frames = (short *)data.constData();
    QVector<double> result;
    for (int  i=0; i < data.length()/2; i ++ ){
        result.append(frames[i]);
    }

    ui->soundView->pushSoundLevel(result);
    parser.pushAmplitude(result);
}

void Window::stop(bool clear){
    qDebug()<<"Stop recording";
    this->audio->stop();
    this->audioBuffer.close();
    if (clear)
        this->parser.clear();
}
void Window::on_actionStartRecording_triggered(){
    this->start();
}


void Window::on_actionStopRecording_triggered(){
    this->stop(true);
}


void Window::on_actionPauseRecording_triggered(){
    this->stop();
}

void Window::setRecordUIState(bool recording){
    ui->actionPauseRecording->setEnabled(recording);
    ui->actionStopRecording->setEnabled(recording);
    ui->actionStartRecording->setEnabled(!recording);
}
