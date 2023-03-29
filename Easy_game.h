#ifndef EASY_GAME_H
#define EASY_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>

class Easy_game: public QGraphicsView{
    Q_OBJECT
public:
    Easy_game(QWidget * parent=0);
    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    int bullets_number = 100;
    QGraphicsTextItem *bullets_label = new QGraphicsTextItem("Bullets: " + QString::number(bullets_number));

    QGraphicsScene * scene;
    Player * player;


public slots:
    //ir restando los bullets : ver funcion en el cpp
    void decrease();
};

#endif // EASY_GAME_H
