#include "Enemy_1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "Bullet.h"
#include "Collector.h"
#include "NodeC.h"
#include "Player.h"
#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Enemy.h"
#include "NodeC.h"
#include "Collector.h"
#include <iostream>
#include "Easy_game.h"
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
            Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);
            int damage = bullet->bullet_damage;

            if (enemy1_life == 0 && damage==0){
                // remove them both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete this;
                return;
                std::cout<<"DANO EN LA BALA " << damage <<std::endl;
            }
            else{
                enemy1_life--;
                damage--;
                scene()->removeItem(colliding_items[i]); // Remove bullet from scene
                return;

            }

        }
    }

    /// 5 es la verdadera velocidaD DE LA BALA
    setPos(x() - enemy1_speed,y());
    if (pos().x() <= 0){
        scene()->removeItem(this);
        delete this;
    }
}


