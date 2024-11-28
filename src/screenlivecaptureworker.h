#ifndef SCREENLIVECAPTUREWORKER_H
#define SCREENLIVECAPTUREWORKER_H

#include <QGuiApplication>
#include <QObject>
#include <QPixmap>
#include <QScreen>
#include <QTimer>

class QScreen;

class ScreenLiveCaptureWorker : public QObject {
    Q_OBJECT

public:
    ScreenLiveCaptureWorker(QObject *parent = nullptr);

public slots:
    void startCapturing();
    void captureScreen();

signals:
    void frameReady(const QImage &image);
    void finished();

private:
    QTimer *timer = nullptr;
};

#endif // SCREENLIVECAPTUREWORKER_H
