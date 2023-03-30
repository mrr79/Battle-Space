//
// Created by mrr on 29/03/23.
//

#ifndef BATTLESPACE_GAME_OVER_H
#define BATTLESPACE_GAME_OVER_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game_Over: public QGraphicsView{
public:
    Game_Over(QWidget * parent=0);
    void main_menu();

    QGraphicsScene * scene;
};


#endif //BATTLESPACE_GAME_OVER_H
