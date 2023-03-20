//
// Created by mrr on 19/03/23.
//
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QPixmap>


class Bullet : public QWidget {
public:
    int x;
    int y;
    QPixmap image;

    Bullet(int x, int y, QPixmap image, QWidget *parent = nullptr) : QWidget(parent) {
        this->x = x;
        this->y = y;
        this->image = image;
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawPixmap(QRect(x, y, 30, 10), image);
    }

    void move() {
        x += 10;
        update();

        // Remove the bullet from the scene when it goes off-screen
        if (x > width()) {
            delete this;
        }
    }
};


class MyShip : public QWidget {
public:
    int x = 50;
    int y = 50;
    QTimer* timer;
    QPixmap bulletImage;

    MyShip(QWidget *parent = nullptr) : QWidget(parent) {
        // Load bullet image
        bulletImage.load("/home/mrr/Desktop/Battle-Space/bullet.png");

        // Set up timer to fire every 1.5 seconds
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyShip::createBullet);
        timer->start(1500);
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.fillRect(QRect(x, y, 50, 50), Qt::blue);
    }

    void keyPressEvent(QKeyEvent *event) override {
        switch (event->key()) {
            case Qt::Key_Up:
                y -= 10;
                break;
            case Qt::Key_Down:
                y += 10;
                break;
        }
        update();
    }

    void createBullet() {
        // Create a new bullet object
        Bullet* bullet = new Bullet(x + 50, y + 25, bulletImage);
        bullet->show();
    }
};


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyShip myShip;
    myShip.show();
    return app.exec();
}

