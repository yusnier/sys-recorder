#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

class InputHandler;
class ScreenLiveCapture;
class ScreenLiveCapture2;
class ScreenLiveCapture3;
class SysRecorder;

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::MainWindow *ui;

    ScreenLiveCapture *screenLiveCapture;
    ScreenLiveCapture2 *screenLiveCapture2;
    ScreenLiveCapture3 *screenLiveCapture3;
    InputHandler *inputHandler;

    SysRecorder *sysRecorder;
};

#endif // MAINWINDOW_H
