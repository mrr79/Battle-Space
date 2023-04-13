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
    Normal_Game(int bullet_speed,int bullets, int ships_number, int health, QWidget * parent=0);

    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    //int bullets_number = 150;

    QTimer *check;

    QGraphicsTextItem *bullets_label;
    QGraphicsTextItem *health_label;

    QGraphicsLineItem *line;

    QGraphicsScene * scene;
    Player * player;
    Collector collector;
    //QGraphicsTextItem *collector_label;

public slots:
    //ir restando los bullets : ver funcion en el cpp
    void decrease_bullets();
    void decrease_health();
    void check_health();
private:
    int width = 800;
    int height = 600;
    int bullets_number;
    int health_number;

};

#endif // NORMAL_GAME_H
