#include "Bullet.h"
//#include "Enemy_2.h"
//#include "Enemy_1.h"
#include <QDebug>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>


Bullet::Bullet()
{
    setPixmap(QPixmap(":/Images/bullet.png").scaled(20,30));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}



void Bullet::move() {
    setPos(x() + 15, y());
    if (pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}