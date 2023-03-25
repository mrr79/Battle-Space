//
// Created by mrr on 24/03/23.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>


class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void bullets();
    void spawn_enemies1();
    void spawn_enemies2();

};


#endif // PLAYER_H