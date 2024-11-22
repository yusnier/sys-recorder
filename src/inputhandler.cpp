#include "inputhandler.h"

InputHandler::InputHandler(QObject *parent, QGraphicsView *graphicsView)
    : QObject{parent}, graphicsView(graphicsView)
{
    mediaPlayer = new QMediaPlayer(parent);

    // videoItem = new QGraphicsVideoItem;
    // mediaPlayer->setVideoOutput(videoItem);
    // graphicsView->scene()->addItem(videoItem);
    // graphicsView->show();

    videoWidget = new QVideoWidget;
    mediaPlayer->setVideoOutput(videoWidget);
    videoWidget->show();

    // audioOutput = new QAudioOutput;
    // audioOutput->setVolume(0.5);  // 0.0 .. 1.0
    // mediaPlayer->setAudioOutput(audioOutput);

    mediaPlayer->setSource(QUrl::fromLocalFile("D:\\Media\\Nvidia\\Black Squad\\Black Squad 2023.05.23 - 19.41.04.06.DVR.mp4"));
    mediaPlayer->play();
}

InputHandler::~InputHandler()
{

    // QMediaPlayer *player = new QMediaPlayer(&w);
    // QGraphicsVideoItem *item = new QGraphicsVideoItem;
    // player->setVideoOutput(item);
    // graphicsView->scene()->addItem(item);
    // graphicsView->show();

    // player->setSource(QUrl::fromLocalFile("D:\\Media\\Nvidia\\Black Squad\\Black Squad 2023.05.23 - 19.41.04.06.DVR.mp4"));
    // player->play();

}
