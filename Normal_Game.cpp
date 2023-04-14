#include "Normal_Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include "Enemy_2.h"
#include "QDebug"
#include <QFont>
#include <QImage>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Game_Over.h"
#include <QGraphicsScene>
#include <QList>
#include "Player.h"
#include <iostream>

Normal_Game::Normal_Game(int bullet_speed, int bullets, int ships_number, int health, QWidget *parent){
    //Escena
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/Images/BG.png")));



    this->bullets_number = bullets;
    this->health_number = health;
    this->shipsnumber =ships_number ;

    this->round=1;

    bullets_label = new QGraphicsTextItem("Bullets: " + QString::number(bullets_number));
    bullets_label->setDefaultTextColor(Qt::red);

    round_label = new QGraphicsTextItem("Round FASE: " + QString::number(round));
    round_label->setDefaultTextColor(Qt::red);

    line = new QGraphicsLineItem(10, 10, 10, 600);
    scene->addItem(line);



    //PLayer en la scene

    Player *player = new Player(collector, bullets,shipsnumber);
    player->setPixmap(QPixmap(":/Images/myship.png").scaled(50,50));

    health_label = new QGraphicsTextItem("Health: " + QString::number(health));

    health_label->setDefaultTextColor(Qt::red);



    //Agregado de el item a la escena
    scene->addItem(player);
    scene->addItem(bullets_label);
    scene->addItem(health_label);
    health_label->setPos(0,20);


    scene->addItem(round_label);
    round_label->setPos(500,20);

    //Hacer rectangulo focusiable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Mostrar scena
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player->setPos(0,150);


    //Timer de las balas
    QTimer *timer_bullets = new QTimer;
    QObject::connect(timer_bullets,SIGNAL(timeout()),player,SLOT(bullets()));
    timer_bullets->start(bullet_speed);
    /*
    //Timer de los enemigos
    QTimer *timer_enemies_1 = new QTimer;
    QObject::connect(timer_enemies_1, SIGNAL(timeout()), player, SLOT(spawn_enemies_1()));
    timer_enemies_1->start(2000);*/

    //Timer de los enemigos
    QTimer *timer_enemies_2 = new QTimer;
    QObject::connect(timer_enemies_2, SIGNAL(timeout()), player, SLOT(spawn_random_enemies()));
    timer_enemies_2->start(3000);

    //CONTADOR DE BALAS
    QObject::connect(timer_bullets,SIGNAL(timeout()),this,SLOT(decrease_bullets()));
    timer_bullets->start(bullet_speed);


    //  PARA CAMBIAR DE ROUNDS=FASES
    QObject::connect(player, SIGNAL(roundChanged()), this, SLOT(handleRoundChanged()));



    check = new QTimer;
    QObject::connect(check,SIGNAL(timeout()),this,SLOT(check_health()));
    check->start(50);

    show();
}

void Normal_Game::decrease_bullets()
{
    if (bullets_number == 0 && collector.collector_size() == 0){
        timer_bullets->stop();
    }
    else{
        bullets_number--;
        bullets_label->setPlainText("Bullets: " + QString::number(bullets_number));
    }
}

void Normal_Game::decrease_health()
{
    if (health_number == 0){
        return;
    }
    else{
        health_number--;
        health_label->setPlainText("Health: " + QString::number(health_number));
    }
}

void Normal_Game::check_health()
{
    if (health_number == 0){
        check->stop();
        Game_Over *game_over = new Game_Over();
        game_over->show();
        this->close();
    }
    else{
        QList<QGraphicsItem *> colliding_items = line->collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy_1)){
                decrease_health();
            }
            if (typeid(*(colliding_items[i])) == typeid(Enemy_2)){
                decrease_health();
            }
        }
    }
}

void Normal_Game::handleRoundChanged() {
    std::cout << "acomodar rounds" << std::endl;
    round++;
    round_label->setPlainText("Rounds: " + QString::number(round));
    if (round == 5) {
        // Stop the game
        // You can add your implementation here to stop the game once the round is 5
        std::cout << "ver que hacer con el juego: perdio o gano " << std::endl;

    }
}
