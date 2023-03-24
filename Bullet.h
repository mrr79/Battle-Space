//
// Created by mrr on 24/03/23.
//

#ifndef BATTLE_SPACE_BULLET_H
#define BATTLE_SPACE_BULLET_H


#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H



#endif //BATTLE_SPACE_BULLET_H
