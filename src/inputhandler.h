#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QAudioOutput>
#include <QGraphicsVideoItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QObject>
#include <QVideoWidget>

class InputHandler : public QObject
{
    Q_OBJECT
public:
    explicit InputHandler(QObject *parent = nullptr, QGraphicsView *graphicsView = nullptr);
    ~InputHandler();

private:
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QGraphicsVideoItem *videoItem;
    QAudioOutput *audioOutput;

    QGraphicsView *graphicsView;

signals:
};

#endif // INPUTHANDLER_H
