#ifndef PLAYER_H
#define PLAYER_H
#include "Collector.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Bullet.h"
#include "EnemyList.h"
#include "Normal_Game.h"
#include "Fase.h"
#include "Strategy.h"
#include "Power.h"

class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    int bullets_number;
    void keyPressEvent(QKeyEvent * event);
    void reset_powers();

    int damage = 10;
    Collector collector;
    Collector usedBullets;
    Fase fase1;
    Fase fase2;

    Player(Collector& collector, int bullets_number, int ships_number, Fase& fase1, Fase& fase2);
    int size_collector;
    int hits;
    QGraphicsTextItem *collector_label;
    QGraphicsTextItem *hits_label;
    void utilizar_poder(QString poder, Strategy strategies[]);
    bool verificar_si_hay_poder(QString poder, Strategy strategies[]);
    Strategy cargar_xml(QString n);


    Strategy strategies[2] = {cargar_xml("XML/Estrategia1.xml"), cargar_xml("XML/Estrategia2.xml")};
    int Poder1;
    int Poder2;
    int Poder3;
    int Poder4;
    int Poder5;
    int Poder6;
    int Poder7;
    int Poder8;

    int getPoder2();
    int getPoder3();
    int getPoder4();
    int getPoder5();
    int getPoder6();
    int getPoder7();
    int getPoder8();

public slots:
    void bullets();
    void spawn_enemies_1();
    void spawn_enemies_2();
    void spawn_enemies();
    void moveBullets();
    void handleBulletCollision();
    void spawn_random_enemies();
    void spawn_random_enemies2();
    void printLists() const;
    void printLists2() const;


    //void create_new_enemy_lists();

private:
    EnemyList enemyList;
    int ships_number;
    int num_enemies = 0;
    int num_enemies_1 = 0;
    int num_enemies_2 = 0;
    int round_aux = 0;
    int round_aux2 = 0;
    EnemyList enemy_list[5];
    EnemyList enemy_list2[5];
    int n = 0;
    int m = 0;                                                                                                                                                       ;;
signals:
    void roundChanged();




};
#endif // PLAYER_H