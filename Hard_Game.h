#ifndef HARD_GAME_H
#define HARD_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>
#include <QTimer>
#include "Player.h"
#include "Fase.h"

class Hard_Game: public QGraphicsView{
Q_OBJECT
public:
    Hard_Game(int bullet_speed,int bullets, int ships_number, int health, QWidget * parent=0);

    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    //int bullets_number = 150;

    QTimer *check;

    QGraphicsTextItem *bullets_label;
    QGraphicsTextItem *health_label;
    QGraphicsTextItem *round_label;
    QGraphicsTextItem *fase_label;

    QGraphicsTextItem *prueba_label;

    QGraphicsLineItem *line;

    QGraphicsScene * scene;
    //Player * player(collector, bullets_number, ships_number);
    Collector collector;
    Fase fase1;
    Fase fase2;
    //QGraphicsTextItem *collector_label;

    int enemy_count;

    int current_round;

    void add_enemies_to_wave(EnemyList *list_enemies);

public slots:
    //ir restando los bullets : ver funcion en el cpp
    void decrease_bullets();
    void decrease_health();
    void check_health();
    void handleRoundChanged();
    void emitSpawnEnemiesSignal();
    void ganar();

private:
    int width = 800;
    int height = 600;
    int bullets_number;
    int health_number;
    int shipsnumber;
    QVector<EnemyList*> wave;
    int round;
    int fase;
    QTimer* timer;
    Player *player;
signals:
    void spawnEnemies();
};

#endif // HARD_GAME_H
