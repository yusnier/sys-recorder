#include "screenlivecaptureworker.h"

#include <QGuiApplication>
#include <QScreen>
#include <QThread>

// ScreenLiveCaptureWorker::ScreenLiveCaptureWorker() {
//     screen = QGuiApplication::primaryScreen();

// }

// ScreenLiveCaptureWorker::~ScreenLiveCaptureWorker() {
//     delete screen;
// }

// void ScreenLiveCaptureWorker::captureScreen() {
//     if (!screen) {
//         return;
//     }

//     while (true) {
//         if (QThread::currentThread()->isInterruptionRequested()) {
//             emit finished();
//             break;
//         }

//         // Grab the screen and convert it to a pixmap
//         // QImage image = screen->grabWindow(0)
//         //                    .toImage()
//         //                    .scaled(screenScaleSize, Qt::KeepAspectRatio, Qt::FastTransformation);
//         // QPixmap pixmap = QPixmap::fromImage(image);

//         QPixmap pixmap = screen->grabWindow(0);

//         emit frameCaptured(pixmap);

//         QThread::msleep(50); // Simulate ~30 FPS
//     }
// }

// void ScreenLiveCaptureWorker::setScreenScaleSize(const QSize &size) {
//     screenScaleSize = size;
// }

ScreenLiveCaptureWorker::ScreenLiveCaptureWorker(QObject *parent) : QObject(parent) {
    // timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &ScreenLiveCaptureWorker::captureScreen);
    // timer->start(33); // ~30 FPS
}

void ScreenLiveCaptureWorker::startCapturing() {
    qDebug() << "ScreenLiveCaptureWorker::startCapturing() executed";
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ScreenLiveCaptureWorker::captureScreen);
    timer->start(100); // ~30 FPS
}

void ScreenLiveCaptureWorker::captureScreen() {
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QPixmap pixmap = screen->grabWindow(0);
        QImage frame = pixmap.toImage().convertToFormat(QImage::Format_RGBA8888);
        emit frameReady(frame);
    }
}
