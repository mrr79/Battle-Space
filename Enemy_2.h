#ifndef RED_ENEMY_H
#define RED_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Player.h"
#include "Collector.h"
#include "EnemyList.h"

class Enemy_2: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    EnemyList* enemy_list;
    EnemyList* enemy_list2;
    int enemy2_life = 2;
    Enemy_2(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy2_speed = 5;
public slots:
    void move();
private:
    Collector& collector;
    void printLists() const;
    void printLists2() const;
};

#endif
