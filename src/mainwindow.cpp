#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "screenlivecapture.h"
#include "screenlivecapture2.h"
#include "screenlivecapture3.h"
#include "sysrecorder.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //screenLiveCapture = new ScreenLiveCapture(ui->widget);
    //screenLiveCapture2 = new ScreenLiveCapture2(ui->widget);
    //screenLiveCapture3 = new ScreenLiveCapture3(ui->widget);

    sysRecorder = new SysRecorder(this);

    // QList<QCapturableWindow> list = QWindowCapture::capturableWindows();
    // for (QCapturableWindow &a: list) {
    //     ui->listWidget_2->addItem(a.description());
    // }
}

MainWindow::~MainWindow()
{
    delete ui;

    //delete screenLiveCapture;
    //delete screenLiveCapture2;
    //delete screenLiveCapture3;
}

void MainWindow::on_pushButton_released()
{
    sysRecorder->record();
    //ui->listWidget->addItem("recording");
}

void MainWindow::on_pushButton_2_released()
{
    sysRecorder->stop();
    //ui->listWidget->addItem("stopping");
}

