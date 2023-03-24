//
// Created by mrr on 24/03/23.
//

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
