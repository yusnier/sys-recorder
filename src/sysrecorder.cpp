#include "sysrecorder.h"

#include <QAudioInput>
#include <QMediaDevices>
#include <QMediaFormat>
#include <QMediaRecorder>
#include <QScreenCapture>
#include <QUrl>

#include <QAudioDevice>

// #include <QAudioInput>
// #include <QMediaCaptureSession>
// #include <QMediaFormat>
// #include <QMediaRecorder>
// #include <QUrl>

SysRecorder::SysRecorder(QObject *parent) {

    QMediaFormat format = QMediaFormat(QMediaFormat::FileFormat::MPEG4);
    format.setVideoCodec(QMediaFormat::VideoCodec::H264);

    recorder = new QMediaRecorder(parent);
    recorder->setQuality(QMediaRecorder::Quality::VeryHighQuality);
    recorder->setMediaFormat(format);
    recorder->setOutputLocation(QUrl::fromLocalFile("C:\\Users\\Yusnier\\Desktop\\Recordings\\video.mp4"));
    recorder->setVideoFrameRate(30.0);
    recorder->setVideoBitRate(1000000);
    recorder->setVideoResolution(QSize(2560, 1440));
    recorder->setEncodingMode(QMediaRecorder::EncodingMode::ConstantQualityEncoding);


    // qDebug() << "Available backends:" << QMediaRecorder::supportedMediaDevices();
    //qDebug() << "Selected backend:" << recorder->mediaDevices();

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QPixmap screenPixmap = screen->grabWindow(0); // Grab the full screen (or specify a window ID)
        screenPixmap.save("C:\\Users\\Yusnier\\Desktop\\Recordings\\screenshot.png");
        // Process or display the screen capture here (e.g., show it in a widget, etc.)
        qDebug() << "Screen captured.";
    } else {
        qWarning() << "Failed to capture screen.";
    }

    QScreenCapture *screenCapture = new QScreenCapture(parent);
    screenCapture->setScreen(screen);
    screenCapture->start();

    QObject::connect(screenCapture, &QScreenCapture::errorOccurred, [](QScreenCapture::Error error, const QString &errorString) {
        qDebug() << "Screen Capture Error:" << error << errorString;
    });


    // Step 2: Set up audio input
    QAudioInput *audioInput = new QAudioInput(QMediaDevices::defaultAudioInput());
    qDebug() << ">>> Default audio input: " << audioInput->device().description();
    const QList<QAudioDevice> audioDevices = QMediaDevices::audioInputs();
    if (audioDevices.isEmpty()) {
        qDebug() << "No audio input devices found!";
        //return 0;
    }
    qDebug() << "Available audio input devices:";
    for (const QAudioDevice &device : audioDevices) {
        qDebug() << "- Name:" << device.description();
    }

    // if (!screenCapture->isActive()) {
    //     qDebug() << "Starting screen capture...";
    //     screenCapture->start();
    // } else {
    //     qDebug() << "Screen capture already active.";
    // }

    session = new QMediaCaptureSession(parent);
    session->setScreenCapture(screenCapture);
    session->setAudioInput(audioInput);
    session->setRecorder(recorder);

    is_recording = false;
}

SysRecorder::~SysRecorder()
{
    delete session;
    delete recorder;
}

void SysRecorder::record()
{
    if (!is_recording) {
        recorder->record();
        is_recording = true;
    }

}

void SysRecorder::pause()
{

}

void SysRecorder::stop()
{
    if (is_recording) {
        recorder->stop();
        is_recording = false;
    }
}
