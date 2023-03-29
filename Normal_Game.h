#ifndef NORMAL_GAME_H
#define NORMAL_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>
#include <QTimer>
class Normal_Game: public QGraphicsView{
    Q_OBJECT
public:
    Normal_Game(QWidget * parent=0);

    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    int bullets_number = 150;

    QGraphicsTextItem *bullets_label = new QGraphicsTextItem("Bullets: " + QString::number(bullets_number));

    QGraphicsScene * scene;
    Player * player;


public slots:
    //ir restando los bullets : ver funcion en el cpp
    void decrease();

};

#endif // NORMAL_GAME_H