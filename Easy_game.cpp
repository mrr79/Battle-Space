#include "Easy_game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include "Collector.h"
#include "NodeC.h"
#include "Player.h"
#include "Bullet.h"


Easy_game::Easy_game(QWidget *parent){
    //scena
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/Images/BG.png")));

    int width = 800;
    int height = 600;
    //velocidad de las balas
    int bullet_speed = 600;


    Collector collector;

    //PLayer en la scene

    Player *player = new Player(collector, bullets_number,8);
    player->setPixmap(QPixmap(":/Images/myship.png").scaled(50,50));

    bullets_label->setDefaultTextColor(Qt::red);

    //Agregado de el item a la escena
    scene->addItem(player);

    //Hacer rectangulo focusiable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Mostrar scena
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player->setPos(0,150);

    scene->addItem(bullets_label);

    collector_label->setDefaultTextColor(Qt::red);
    scene->addItem(collector_label);

    //Timer de las balas
    QTimer *timer_bullets = new QTimer;
    QObject::connect(timer_bullets,SIGNAL(timeout()),player,SLOT(bullets()));
    timer_bullets->start(bullet_speed);

    //Timer de los enemigos
    QTimer *timer_enemies_1 = new QTimer;
    QObject::connect(timer_enemies_1, SIGNAL(timeout()), player, SLOT(spawn_enemies_1()));
    timer_enemies_1->start(2000);

    //Timer de los enemigos
    QTimer *timer_enemies_2 = new QTimer;
    QObject::connect(timer_enemies_2, SIGNAL(timeout()), player, SLOT(spawn_enemies_2()));
    timer_enemies_2->start(3000);

//CONTADOR DE BALAS
    QObject::connect(timer_bullets,SIGNAL(timeout()),this,SLOT(decrease()));
    timer_bullets->start(bullet_speed);

    show();

}

void Easy_game::decrease()
{
    if (bullets_number == 0){
        timer_bullets->stop();
    }
    else{
        bullets_number--;
        bullets_label->setPlainText("Bullets: " + QString::number(bullets_number));
        //bullets_label->setPlainText("B en collector: " + QString::number(colec));
    }
}

