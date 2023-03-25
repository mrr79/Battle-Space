//
// Created by mrr on 24/03/23.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT

    Player(QGraphicsItem *parent);

public:
    void keyPressEvent(QKeyEvent * event);
public:
    Player();

public slots:
    void bullets();
    void spawn_enemies();

};
#endif // PLAYER_H