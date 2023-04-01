

#include <QGraphicsRectItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"

#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();
    int bullet_damage = 1;
public slots:
    void move();
//public signals:
    //void positionOutOfRange();
};

#endif // BULLET_H

