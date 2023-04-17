#include "Bullet.h"
#include "Enemy_2.h"
#include "Enemy_1.h"
#include <QDebug>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Collector.h"
#include "NodeC.h"
#include "Player.h"

Bullet::Bullet(): bullet_damage()
{

    setPixmap(QPixmap(":/Images/bullet.png").scaled(20,30));

    QTimer *timer = new QTimer;

    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

//Collector *collector = new Collector();



void Bullet::move() {
    /*
    setPos(x() + 15, y());

    if (pos().x() > 800) {
        //emit collisionDetected();
        // Out of range
        //scene()->removeItem(this);
    }
     */
}


void Bullet::handleCollision()
{
    QList<QGraphicsItem *> CollidingItems = collidingItems();
    for (int i = 0; i < CollidingItems.size(); ++i) {
        if (dynamic_cast<Enemy_1*>(CollidingItems[i]) || dynamic_cast<Enemy_2*>(CollidingItems[i])) {
            emit collisionDetected();
        }
    }
}

void Bullet::reduceDamage() {
    bullet_damage = bullet_damage*0.8;
}