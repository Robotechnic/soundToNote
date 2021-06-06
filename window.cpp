#include "window.h"
#include "ui_window.h"



Window::Window(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Window),
      chart(new SoundChart())
{
    ui->setupUi(this);

    //setup charts
    chart->setTitle("Sound level");
    chart->legend()->hide();
    ui->soundView->setChart(chart);
    //ui->soundView->setRenderHint(QPainter::Antialiasing);

    //setup audio input
    format.setSampleRate(11025);
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


}

Window::~Window()
{
    delete ui;
}

void Window::processAudioFrame(QByteArray data, int lenght){
    if(lenght > 0)
    {
        for (int i=0; i<lenght/20; i++, data+=20) {
            const qint16 pcmSample = qFromLittleEndian<qint16>(data.data());
            this->chart->pushSoundLevel(pcmSample/32768.0);
        }
    }
}

void Window::stateManager(QAudio::State newState) {
    qDebug()<<newState;
}

void Window::on_startRecording_clicked()
{
    qDebug()<<"Start recording";
    auto io = this->audio->start();

    connect(io,&QIODevice::readyRead,[this,io]{
        int len = audio->bytesReady();

        QByteArray buff(len,0);
        int buffLenght = io->read(buff.data(),len);
        if (buffLenght>0){
            this->processAudioFrame(buff.constData(),buffLenght);
        }
    });
}


void Window::on_stopRecording_clicked()
{
    qDebug()<<"Stop recording";
    this->audio->stop();
}

