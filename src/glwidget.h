#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QThread>
#include <QTimer>
#include <QImage>
#include <QMutex>

//#include "ScreenWorker.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent), textureID(0) {}

    void updateTexture(const QImage &frame) {
        QMutexLocker locker(&mutex);
        latestFrame = frame.copy();
        update();  // Trigger a repaint
    }

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    void paintGL() override {
        //qDebug() << "test";
        QMutexLocker locker(&mutex);
        if (!latestFrame.isNull()) {
            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, latestFrame.width(), latestFrame.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, latestFrame.bits());

            // Clear and draw a full-screen quad with the texture
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glBegin(GL_QUADS);
            glTexCoord2f(0, 1); glVertex2f(-1, -1);
            glTexCoord2f(1, 1); glVertex2f(1, -1);
            glTexCoord2f(1, 0); glVertex2f(1, 1);
            glTexCoord2f(0, 0); glVertex2f(-1, 1);
            glEnd();
        }
    }

private:
    GLuint textureID;
    QImage latestFrame;
    QMutex mutex;
};

#endif // GLWIDGET_H
