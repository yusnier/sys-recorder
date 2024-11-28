#ifndef SYSRECORDER_H
#define SYSRECORDER_H

#include <QMediaCaptureSession>
#include <QMediaRecorder>

class SysRecorder : public QObject
{
    Q_OBJECT
private:
    QMediaCaptureSession *session;
    QMediaRecorder *recorder;
    bool is_recording;

public:
    SysRecorder(QObject *parent = nullptr);
    ~SysRecorder();

    void record();
    void pause();
    void stop();
};

#endif // SYSRECORDER_H
