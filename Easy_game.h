//
// Created by mrr on 24/03/23.
//

#ifndef BATTLE_SPACE_EASY_GAME_H
#define BATTLE_SPACE_EASY_GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"

class Easy_game: public QGraphicsView{
public:
    Easy_game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;

};

#endif // EASY_GAME_H
