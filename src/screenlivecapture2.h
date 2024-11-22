#ifndef SCREENLIVECAPTURE2_H
#define SCREENLIVECAPTURE2_H

#include <QGridLayout>
#include <QScreen>
#include <QTimer>
#include <QWidget>

class ScreenLiveCapture2 : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenLiveCapture2(QWidget *parent = nullptr);
    ~ScreenLiveCapture2();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void captureScreen();

private:
    QGridLayout *gridLayout;
    QImage buffer;
    QTimer *timer;
    QScreen *screen;
};

#endif // SCREENLIVECAPTURE2_H
