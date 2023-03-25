//
// Created by mrr on 24/03/23.
//

#include "Bullet.h"
#include "Enemy_1.h"
#include "Enemy_2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Bullet::Bullet()
{
    setPixmap(QPixmap(":/Images/bullet.png").scaled(50,50));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy_2)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Enemy_1)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x() + 15,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}