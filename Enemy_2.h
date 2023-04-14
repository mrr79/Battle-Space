#ifndef RED_ENEMY_H
#define RED_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Player.h"
#include "Collector.h"

class Enemy_2: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    int enemy2_life = 2;
    Enemy_2(Collector& collector);
    int enemy2_speed = 5;
public slots:
    void move();
private:
    Collector& collector;
};

#endif
