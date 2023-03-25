//
// Created by mrr on 25/03/23.
//

#ifndef BATTLE_SPACE_ENEMY_1_H
#define BATTLE_SPACE_ENEMY_1_H


#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy_1: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy_1();
public slots:
    void move();
};


#endif // Enemy_1_H
