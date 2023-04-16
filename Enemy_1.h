#ifndef BLUE_ENEMY_H
#define BLUE_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Collector.h"

class Enemy_1: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy_1(Collector& collector);
    int enemy1_life = 1;
    int enemy1_speed = 10;
public slots:
    void move();
private:
    Collector& collector;
signals:
    void aboutToBeRemoved(Enemy_1* enemy);

};


#endif // BLUE_ENEMY_H


