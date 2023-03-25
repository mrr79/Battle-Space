//
// Created by mrr on 25/03/23.
//

#ifndef BATTLE_SPACE_ENEMY_2_H
#define BATTLE_SPACE_ENEMY_2_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy_2: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy_2();
public slots:
    void move();
};



#endif //BATTLE_SPACE_ENEMY_2_H
