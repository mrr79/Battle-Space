#ifndef HARD_GAME_H
#define HARD_GAME_H

#include <QTimer>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"


class Hard_Game: public QGraphicsView{
Q_OBJECT

public:
    Hard_Game(QWidget * parent=0);

    Collector collector;
    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    int bullets_number = 200;
    QGraphicsTextItem *bullets_label = new QGraphicsTextItem("Bullets: " + QString::number(bullets_number));

    QGraphicsScene * scene;
    Player * player;

public slots:
    //ir restando los bullets : ver funcion en el cpp
    //void decrease();

};

#endif // HARD_GAME_H
