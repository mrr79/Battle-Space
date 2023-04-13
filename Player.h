#ifndef PLAYER_H
#define PLAYER_H
#include "Collector.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Bullet.h"

class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    int bullets_number;
    void keyPressEvent(QKeyEvent * event);

    int damage = 10;
    Collector collector;
    Collector usedBullets;

    Player(Collector& collector, int bullets_number);
    int size_collector;
    int hits;
    QGraphicsTextItem *collector_label;
    QGraphicsTextItem *hits_label;
public slots:
    void bullets();
    void spawn_enemies_1();
    void spawn_enemies_2();
    void spawn_enemies();
    void moveBullets();
    void handleBulletCollision();



};
#endif // PLAYER_H