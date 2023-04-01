#ifndef BLUE_ENEMY_H
#define BLUE_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy_1: public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy_1();
    int enemy1_life = 1;
    int enemy1_speed = 10;
public slots:
    void move();
};


#endif // BLUE_ENEMY_H
