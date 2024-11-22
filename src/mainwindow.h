#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

class InputHandler;
class ScreenLiveCapture;
class ScreenLiveCapture2;

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

private:
    Ui::MainWindow *ui;

    ScreenLiveCapture *screenLiveCapture;
    ScreenLiveCapture2 *screenLiveCapture2;
    InputHandler *inputHandler;
};
#endif // MAINWINDOW_H
