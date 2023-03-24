//
// Created by mrr on 24/03/23.
//

#ifndef MyShip_H
#define MyShip_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class MyShip : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    MyShip();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void shoot();
    void spawn();
};

#endif // MyShip_H


