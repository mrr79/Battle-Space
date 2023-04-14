#ifndef PLAYER_H
#define PLAYER_H
#include "Collector.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Bullet.h"
#include "EnemyList.h"
#include "Normal_Game.h"

class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    int bullets_number;
    void keyPressEvent(QKeyEvent * event);

    int damage = 10;
    Collector collector;
    Collector usedBullets;

    Player(Collector& collector, int bullets_number, int ships_number);
    int size_collector;
    int hits;
    QGraphicsTextItem *collector_label;
    QGraphicsTextItem *hits_label;
    //Normal_Game* normal_game= Normal_Game;
public slots:
    void bullets();
    void spawn_enemies_1();
    void spawn_enemies_2();
    void spawn_enemies();
    void moveBullets();
    void handleBulletCollision();
    void spawn_random_enemies();

private:
    EnemyList enemyList;
    int ships_number;
    int num_enemies = 0;
    int num_enemies_1 = 0;
    int num_enemies_2 = 0;
signals:
    void roundChanged();




};
#endif // PLAYER_H