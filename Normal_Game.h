//
// Created by mrr on 24/03/23.
//

#ifndef BATTLE_SPACE_NORMAL_GAME_H
#define BATTLE_SPACE_NORMAL_GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"

class Normal_Game: public QGraphicsView{
public:
    Normal_Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;

};

#endif // NORMAL_GAME_H
