//
// Created by mrr on 24/03/23.
//

#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H