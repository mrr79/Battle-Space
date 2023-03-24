//
// Created by mrr on 24/03/23.
//

#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include <QDebug>

Bullet::Bullet(): QObject(), QGraphicsPixmapItem() {
    // Set the pixmap
    QPixmap pixmap("/home/mrr/Desktop/Battle-Space/bullet.png");
    setPixmap(pixmap);

    // Connect the move timer to the move slot
    QTimer * moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(200);
}

void Bullet::move() {
    // Move the bullet to the right
    setPos(x() + 10, y());

    // Check for collisions with enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Remove both the enemy and the bullet
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // Delete both the enemy and the bullet
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // If the bullet goes off the screen, remove and delete it
    if (pos().x() + pixmap().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}


