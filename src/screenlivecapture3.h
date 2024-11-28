#ifndef SCREENLIVECAPTURE3_H
#define SCREENLIVECAPTURE3_H

#include <QGridLayout>
#include <QLabel>
#include <QScreen>
#include <QTimer>
#include <QWidget>

class GLWidget;

class ScreenLiveCapture3 : public QLabel
{
    Q_OBJECT

public:
    explicit ScreenLiveCapture3(QWidget *parent = nullptr);
    ~ScreenLiveCapture3();

private slots:
    void updateFrame(const QImage &frame);

private:
    QGridLayout *gridLayout;
    QImage buffer;
    QTimer *timer;
    QScreen *screen;
    GLWidget *glWidget;
};

#endif // SCREENLIVECAPTURE3_H
