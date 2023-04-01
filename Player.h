#ifndef PLAYER_H
#define PLAYER_H
#include "Collector.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int bullets_number;
    void keyPressEvent(QKeyEvent * event);
    Player(int bullets_number);
    int damage = 10;
public slots:
    void bullets();
    void spawn_enemies_1();
    void spawn_enemies_2();
    void spawn_enemies();

private:
    Collector collector; // declare an instance of the Collector class

};
#endif // PLAYER_H
