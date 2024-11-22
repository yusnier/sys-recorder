#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "screenlivecapture.h"
#include "screenlivecapture2.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //screenLiveCapture = new ScreenLiveCapture(ui->widget);
    screenLiveCapture2 = new ScreenLiveCapture2(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;

    //delete screenLiveCapture;
    delete screenLiveCapture2;
}
