//
// Created by mrr on 19/03/23.
//

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>




class Ship : public QGraphicsPixmapItem {
public:
    Ship(QGraphicsItem *parent = nullptr) : QGraphicsPixmapItem(parent) {
        setPixmap(QPixmap("/home/mrr/Desktop/Battle-Space/myship.png").scaled(50, 50));
        setPos(-200, 125);
    }


    void moveUp() {
        setY(y() - 10);
    }


    void moveDown() {
        setY(y() + 10);
    }
};


class Bullet : public QGraphicsPixmapItem {
public:
    Bullet(QGraphicsItem *parent = nullptr) : QGraphicsPixmapItem(parent) {
        setPixmap(QPixmap("/home/mrr/Desktop/Battle-Space/bullet.png").scaled(30, 30));
        setEnabled(true); // make the bullet item enabled
        setVisible(true); // make the bullet item visible
    }


    void advance(int phase) override {
        if (phase == 0) return;
        setX(x() + 10); // move bullet to the right by 10 pixels
        if (x() > 300) scene()->removeItem(this); // remove bullet when it reaches the right edge of the screen
    }


};


class Game : public QGraphicsView {
Q_OBJECT // Add the Q_OBJECT macro to enable slots and signals

public:
    Game(QWidget *parent = nullptr) : QGraphicsView(parent) {
        // Set up the game scene
        QGraphicsScene *scene = new QGraphicsScene(this);
        setScene(scene);
        setFixedSize(500, 500);




        // Add the ship to the scene
        ship = new Ship();
        scene->addItem(ship);




        // Start the timer for shooting bullets
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update())); // update the view in each frame
        connect(timer, SIGNAL(timeout()), this, SLOT(shootBullet()));
        timer->start(1000); // fire every 1 second


    }




protected:
    void keyPressEvent(QKeyEvent *event) override {
        switch (event->key()) {
            case Qt::Key_Up:
                ship->moveUp();
                break;
            case Qt::Key_Down:
                ship->moveDown();
                break;
        }
    }


private slots:
    void shootBullet() {
        // Create a new bullet and add it to the scene
        Bullet *bullet = new Bullet();
        bullet->setPos(ship->x() + 50, ship->y() + 25);
        scene()->addItem(bullet);
    }


private:
    Ship *ship;
};




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Game game;
    game.show();
    return app.exec();
}

#include <nave_jugador.moc>