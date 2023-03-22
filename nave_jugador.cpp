//
// Created by mrr on 19/03/23.
//

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QImage>
#include <QTimer>

class MyShip : public QWidget {
public:
    int x = 50;
    int y = 50;
    QImage image;
    int bulletX = -1; // -1 sigifica que no hay bala activa en este momento
    int bulletY = -1;

    MyShip(QWidget *parent = nullptr) : QWidget(parent) {
        // Load the image from file
        image.load("/home/mrr/Desktop/Battle-Space/myship.png");

        // Create a timer that fires every second and triggers bullet
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyShip::createBullet);
        timer->start(500); // cada cuanto se dispara una bala

        setFocusPolicy(Qt::StrongFocus); // set the focus policy: accept keyboard events
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(QRect(x, y, 50, 50), image);

        if (bulletX != -1 && bulletY != -1) {
            // draw the bullet if is active
            QImage bulletImage;
            bulletImage.load("/home/mrr/Desktop/Battle-Space/bullet.png");
            painter.drawImage(QRect(bulletX, bulletY, 20, 20), bulletImage);
        }
    }

    void keyPressEvent(QKeyEvent *event) override {
        // Move the ship ARRIBA Y ABAJO
        switch (event->key()) {
            case Qt::Key_Up:
                y -= 10;
                break;
            case Qt::Key_Down:
                y += 10;
                break;
            default:
                QWidget::keyPressEvent(event);
        }
        update();
    }

private:
    void createBullet() {
        if (bulletX == -1 && bulletY == -1) {
            // Create un bullet si hay otro activo.
            bulletX = x + 50;
            bulletY = y + 25;

            //  timer fires every 20 useconds and moves the bullet
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MyShip::moveBullet);
            timer->start(20);//REALMENTE la velocidad a la que se mueve la bala
        }
    }

    void moveBullet() {
        if (bulletX > width()) {
            // Deactivate bullet when it goes off-screen
            bulletX = -1;
            bulletY = -1;
            sender()->deleteLater(); // Delete the  QTimer)
        } else {
            bulletX += 10;
            update();
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyShip myShip;
    myShip.show();
    return app.exec();
}
