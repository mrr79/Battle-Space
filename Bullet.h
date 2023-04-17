#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Enemy_1.h"



#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();
    int bullet_damage = 1;
    Collector *collector = new Collector();
public slots:
    void move();

    void reduceDamage();

signals:
    void collisionDetected();

protected slots:
    void handleCollision();
//public signals:
    //void positionOutOfRange();
};

#endif // BULLET_H

