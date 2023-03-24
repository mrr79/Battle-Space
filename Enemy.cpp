//
// Created by mrr on 24/03/23.
//

#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int

#include <QDebug>

Enemy::Enemy() : QObject(), QGraphicsPixmapItem()
{
    // Set the enemy image
    setPixmap(QPixmap("/home/mrr/Desktop/Battle-Space/e1.png").scaled(50, 50));

    // Set random position on the right side of the screen
    int random_number = rand() % 300 + 400; // Random number between 400 and 700
    setPos(random_number, 0);

    // Connect to move function
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    // Move enemy to the left
    setPos(x()-5, y());

    // Remove enemy if it goes off screen
    if (pos().x() + pixmap().width() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
