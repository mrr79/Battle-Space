//
// Created by mrr on 25/03/23.
//

#include "Enemy_1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>

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
    setPos(x() - 10,y());
    if (pos().x() <= 0){
        scene()->removeItem(this);
        delete this;
    }
}
