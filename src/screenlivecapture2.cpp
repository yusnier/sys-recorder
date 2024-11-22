#include "screenlivecapture2.h"

#include <QGuiApplication>
#include <QPainter>

ScreenLiveCapture2::ScreenLiveCapture2(QWidget *parent) : QWidget{parent} {
    setAttribute(Qt::WA_OpaquePaintEvent); // Optimize paint event
    setAttribute(Qt::WA_NoSystemBackground);

    gridLayout = new QGridLayout(parent);
    gridLayout->addWidget(this);

    screen = QGuiApplication::primaryScreen();
    buffer.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    //this->setAlignment(Qt::AlignHCenter);
    //this->setStyleSheet("background-color: lightblue;");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ScreenLiveCapture2::captureScreen);
    timer->start(100); // Capture every 100 ms
}

ScreenLiveCapture2::~ScreenLiveCapture2() {

}

void ScreenLiveCapture2::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing, true);
    if (!buffer.isNull()) {
        painter.drawImage(rect(), buffer);
    }
}

void ScreenLiveCapture2::captureScreen() {
    if (screen) {
        // Capture the screen into the buffer
        buffer = screen->grabWindow(0).toImage();
            // .scaled(this->size(), Qt::KeepAspectRatio, Qt::FastTransformation);
        update(); // Schedule a paint event
    }
}
