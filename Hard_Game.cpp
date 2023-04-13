#include "Hard_Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Hard_Game::Hard_Game(QWidget *parent){
    //Escena
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //scene->setBackgroundBrush(QBrush(QImage(":/Images/BG.png")));

    int width = 800;
    int height = 600;
    int bullet_speed = 900;

    //Item en la escena
    Player *player = new Player(collector, bullets_number);
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

    //Timer de las balas
    QTimer *timer_bullets = new QTimer;
    QObject::connect(timer_bullets,SIGNAL(timeout()),player,SLOT(bullets()));
    timer_bullets->start(bullet_speed);

    //Timer de los enemigos
    QTimer *timer_enemies_1 = new QTimer;
    QObject::connect(timer_enemies_1, SIGNAL(timeout()), player, SLOT(spawn_enemies_1()));
    timer_enemies_1->start(10000);

    //Timer de los enemigos
    QTimer *timer_enemies_2 = new QTimer;
    QObject::connect(timer_enemies_2, SIGNAL(timeout()), player, SLOT(spawn_enemies_2()));
    timer_enemies_2->start(10000);

    QTimer *timer_enemies = new QTimer;
    QObject::connect(timer_enemies,SIGNAL(timeout()),player,SLOT(spawn_enemies()));
    timer_enemies->start(2000);

    //CONTADOR DE BALAS
    QObject::connect(timer_bullets,SIGNAL(timeout()),this,SLOT(decrease()));
    timer_bullets->start(bullet_speed);

    show();
}

void Hard_Game::decrease()
{
    if (bullets_number == 0 && collector.collector_size() == 0){
        timer_bullets->stop();
    }
    else{
        bullets_number--;
        bullets_label->setPlainText("Bullets: " + QString::number(bullets_number));
    }
}