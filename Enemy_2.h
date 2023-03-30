#ifndef RED_ENEMY_H
#define RED_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy_2: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    int red_life = 2;
    Enemy_2();
public slots:
    void move();
};

#endif
