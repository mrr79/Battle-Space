#include "Enemy_1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "Bullet.h"

Enemy_1::Enemy_1()
{
    int random_number = rand() % 550;

    setPos(800,random_number);

    setPixmap(QPixmap(":/Images/e1"));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy_1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x() - 10,y());
    if (pos().x() <= -1){
        scene()->removeItem(this);
        delete this;
    }
}
