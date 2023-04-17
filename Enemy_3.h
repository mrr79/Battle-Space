//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_ENEMY_3_H
#define BATTLESPACE_ENEMY_3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Collector.h"
#include "Fase.h"

class Enemy_3{};
/*: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    EnemyList* enemy_list;
    EnemyList* enemy_list2;
    Enemy_3(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy3_life = 1;
    int enemy3_speed = 10;
    Enemy_3* self_ptr; // Agregar un puntero a Enemy_1 como miembro de la clase

signals:
    void hitByBullet();
public slots:
    void move();
private:
    Collector& collector;

    void printLists() const;
    void printLists2() const;
};
*/

#endif //BATTLESPACE_ENEMY_3_H
