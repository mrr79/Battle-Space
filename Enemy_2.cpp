#include "Enemy_2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "Bullet.h"
#include <iostream>
using namespace std;

Enemy_2::Enemy_2()
{
    int random_number = rand() % 550;

    setPos(800,random_number);

    setPixmap(QPixmap(":/Images/E2"));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy_2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Bullet)) {
            Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);
            int damage = bullet->bullet_damage;

            if (enemy2_life == 0 && damage == 0) {
                // remove both bullet and enemy
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                scene()->removeItem(this);
                delete this;
                return;
            }
            else {
                enemy2_life--;
                damage--;
                // remove the bullet
                scene()->removeItem(colliding_items[i]);
                return;
            }
        }
    }

    setPos(x() - enemy2_speed, y());
    if (pos().x() < 0) {
        // remove and delete the enemy object
        scene()->removeItem(this);
        delete this;
    }
}