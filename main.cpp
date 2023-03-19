#include <iostream>

#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>

class MyShip : public QWidget {
public:
    int x = 50;
    int y = 50;

    MyShip(QWidget *parent = nullptr) : QWidget(parent) {}

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
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyShip myShip;
    myShip.show();
    return app.exec();
}
