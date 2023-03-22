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
    int bulletX = -1; // -1 means no bullet is currently active
    int bulletY = -1;

    MyShip(QWidget *parent = nullptr) : QWidget(parent) {
        // Load the image from file
        image.load("/home/mrr/Desktop/Battle-Space/myship.png");

        // Create a timer that fires every second and triggers the creation of a bullet
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyShip::createBullet);
        timer->start(1000);

        // Set the focus policy to accept keyboard events
        setFocusPolicy(Qt::StrongFocus);
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(QRect(x, y, 50, 50), image);

        if (bulletX != -1 && bulletY != -1) {
            // Draw the bullet if it's active
            painter.fillRect(QRect(bulletX, bulletY, 10, 5), Qt::red);
        }
    }

    void keyPressEvent(QKeyEvent *event) override {
        // Move the ship up or down depending on the arrow key pressed
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
            // Create a new bullet if there isn't one currently active
            bulletX = x + 50;
            bulletY = y + 25;

            // Create a timer that fires every 20 microseconds and moves the bullet
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MyShip::moveBullet);
            timer->start(20);
        }
    }

    void moveBullet() {
        if (bulletX > width()) {
            // Deactivate the bullet when it goes off-screen
            bulletX = -1;
            bulletY = -1;
            sender()->deleteLater(); // Delete the sender (the QTimer)
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
