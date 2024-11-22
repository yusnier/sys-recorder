#include "screenlivecapture.h"

#include <QGuiApplication>
#include <QScreen>

ScreenLiveCapture::ScreenLiveCapture(QWidget *parent) : QLabel(parent) {
    setAttribute(Qt::WA_OpaquePaintEvent); // Optimize paint event
    setAttribute(Qt::WA_NoSystemBackground);

    gridLayout = new QGridLayout(parent);
    gridLayout->addWidget(this);

    this->setAlignment(Qt::AlignHCenter);
    this->setStyleSheet("background-color: lightblue;");

    // Set a timer to capture frames periodically
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ScreenLiveCapture::captureScreen);
    timer->start(100);  // Capture every 100 ms
}

ScreenLiveCapture::~ScreenLiveCapture() {
    delete gridLayout;

    if (timer->isActive()) {
        timer->stop();
    }
    delete timer;
}

void ScreenLiveCapture::captureScreen() {
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        // Grab the screen and convert it to a pixmap
        QImage image = screen->grabWindow(0)
                           .toImage()
                           .scaled(this->size(), Qt::KeepAspectRatio, Qt::FastTransformation);

        QPixmap pixmap = QPixmap::fromImage(image);

        //qDebug() << pixmap.size();
        // Update the label with the new image
        setPixmap(pixmap);
    }
}
