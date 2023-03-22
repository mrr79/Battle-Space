//
// Created by mrr on 19/03/23.
//

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QImage>

class MyShip : public QWidget {
public:
    int x = 50;
    int y = 50;
    QImage image;

    MyShip(QWidget *parent = nullptr) : QWidget(parent) {
        // Load the image from file
        image.load("/home/mrr/Desktop/Battle-Space/myship.png");
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(QRect(x, y, 50, 50), image);
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
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyShip myShip;
    myShip.show();
    return app.exec();
}
