#ifndef BLUE_ENEMY_H
#define BLUE_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Collector.h"
#include "Fase.h"

class Enemy_1: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    EnemyList* enemy_list;
    EnemyList* enemy_list2;
    Enemy_1(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy1_life = 1;
    int enemy1_speed = 10;
    Enemy_1* self_ptr; // Agregar un puntero a Enemy_1 como miembro de la clase

signals:
    void hitByBullet();
public slots:
    void move();
private:
    Collector& collector;

    void printLists() const;
    void printLists2() const;
};


#endif // BLUE_ENEMY_H


