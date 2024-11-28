#include "screenlivecapture3.h"

#include "glwidget.h"
#include "screenlivecaptureworker.h"

#include <QGuiApplication>
#include <QPainter>
#include <QThread>
#include <QTimer>

ScreenLiveCapture3::ScreenLiveCapture3(QWidget *parent) : QLabel(parent) {
    // setAttribute(Qt::WA_OpaquePaintEvent); // Optimize paint event
    // setAttribute(Qt::WA_NoSystemBackground);


    glWidget = new GLWidget(this);
    //setCentralWidget(glWidget);

    gridLayout = new QGridLayout(parent);
    gridLayout->addWidget(glWidget);

    this->setAlignment(Qt::AlignHCenter);
    this->setStyleSheet("background-color: lightblue;");





    // Set up the worker thread
    QThread *workerThread = new QThread(this);
    ScreenLiveCaptureWorker *worker = new ScreenLiveCaptureWorker;
    //worker->setScreenScaleSize(this->size());

    worker->moveToThread(workerThread);

    // connect(workerThread, &QThread::started, worker, &ScreenWorker::startCapturing);
    // connect(worker, &ScreenWorker::frameReady, glWidget, &GLWidget::updateTexture, Qt::QueuedConnection);
    // connect(worker, &ScreenWorker::finished, workerThread, &QThread::quit);
    // connect(workerThread, &QThread::finished, worker, &ScreenWorker::deleteLater);

    connect(workerThread, &QThread::started, worker, &ScreenLiveCaptureWorker::startCapturing);
    connect(worker, &ScreenLiveCaptureWorker::frameReady, glWidget, &GLWidget::updateTexture, Qt::QueuedConnection);
    connect(worker, &ScreenLiveCaptureWorker::finished, workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished, worker, &ScreenLiveCaptureWorker::deleteLater);

    workerThread->start();

    // Set a timer to capture frames periodically
    //timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &ScreenLiveCapture::captureScreen);
    //timer->start(100);  // Capture every 100 ms
}

ScreenLiveCapture3::~ScreenLiveCapture3() {

}

void ScreenLiveCapture3::updateFrame(const QImage &frame) {
    if (!frame.isNull()) {
        QPixmap pixmap = QPixmap::fromImage(frame);
        this->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }

    //this->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
}
