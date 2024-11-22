#ifndef SCREENLIVECAPTURE_H
#define SCREENLIVECAPTURE_H

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

class ScreenLiveCapture : public QLabel
{
    Q_OBJECT

public:
    explicit ScreenLiveCapture(QWidget *parent = nullptr);
    ~ScreenLiveCapture();

private slots:
    void captureScreen();

private:
    QGridLayout *gridLayout;
    QTimer *timer;
};

#endif // SCREENLIVECAPTURE_H
