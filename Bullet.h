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
//public signals:
    //void positionOutOfRange();
};

#endif // BULLET_H
