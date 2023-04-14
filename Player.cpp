#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

#include <iostream>
#include <QTimer>
#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Enemy.h"
#include "NodeC.h"
#include "Collector.h"
#include <iostream>
#include "Easy_game.h"
#include "Bullet.h"
using namespace std;
// mover jugador arriba y abajo
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() < 500){
            setPos(x(),y()+10);
        }
    }
}

Player::Player(Collector& collector, int bullets_number)
        : collector(collector), bullets_number(bullets_number)
{
    this->bullets_number = bullets_number;
    connect(this, &Player::handleBulletCollision, this, &Player::handleBulletCollision);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveBullets);
    timer ->setInterval(50);
    timer -> start();
}


// disparo automatico

void Player::bullets()
{
    if (bullets_number != 0){
        Bullet *bullet = new Bullet();
        collector.insertar_collector((void *) bullet);
        bullet->setPos(x()+100,y()+20);

        // add bullet to the scene
        scene()->addItem(bullet);


        bullets_number--;
    } else {
        //cout << "Se acabaron las balas" << endl;
        if (usedBullets.collector_size() > 0) {
            Bullet *bullets = new Bullet();
            bullets = static_cast<Bullet *>(usedBullets.getHead()->valor);
            usedBullets.elimPos(0);
            bullets->setPos(x(), y());
            collector.insertar_collector((void *) bullets);
        }
    }
    /*
    std::cout << "items en collector: " << collector.collector_size() << std::endl;
    if (bullets_number == 0 && collector.collector_size() == 0){
        std::cout << "dijo que todo era 0" << std::endl;
        return;
    }
    if (bullets_number == 0 && collector.collector_size() != 0) {
        void* first_collector = collector.get_first_collector();
        if (first_collector != nullptr) {
            if (Bullet* bullet_reusada = static_cast<Bullet*>(first_collector)){
                std::cout << "Casteo==True" << std::endl;
                bullet_reusada->setPos(x() + 100, y() + 20);
                scene()->addItem(bullet_reusada);
            }

            collector.eliminar_nodo_collector(first_collector);
            //
            //

        }
    }

    else
    {
        Bullet *bullet = new Bullet();
        collector.insertar_collector((void *) bullet);
        bullet->setPos(x()+100,y()+20);

        // add bullet to the scene
        scene()->addItem(bullet);


        bullets_number--;
    }

    int size_collector =  collector.collector_size();
    collector_label = new QGraphicsTextItem("Collector: " + QString::number(size_collector));
    scene()->addItem(collector_label);
    collector_label->setPos(200,0);
    collector_label->setDefaultTextColor(Qt::red);

    int hits = (size_collector-bullets_number);
    hits_label = new QGraphicsTextItem("Hits: " + QString::number(hits));
    scene()->addItem(hits_label);
    hits_label->setPos(200,20);
    hits_label->setDefaultTextColor(Qt::red);
    */
}



void Player::handleBulletCollision()
{
    Bullet *bullet = static_cast<Bullet *>(sender());
    if (collector.en_collector((void *) sender())) {
        collector.eliminar_nodo_collector((void *) sender());
    }

}

void Player::moveBullets(){
    cout << "Se deberia de poder mover la bala: " << endl;
    for (int i = 0; i < collector.collector_size(); i++){
        Bullet* bullet = static_cast<Bullet*>(collector.getPos(i));
        bullet -> setPos(bullet->pos().x() + 10, bullet -> pos().y());
        if (bullet -> pos().x() > 800){
            cout << "SE SALIO " << endl;
            collector.elimPos(i);
            bullet -> reduceDamage();
            usedBullets.insertar_collector((void *) bullet);
        }
    }
}


void Player::spawn_enemies_1()
{
    Enemy_1 *enemy_1 = new Enemy_1(collector);
    scene()->addItem(enemy_1);
}

void Player::spawn_enemies_2()
{
    Enemy_2 *enemy_2 = new Enemy_2(collector);
    scene()->addItem(enemy_2);
}

void Player::spawn_enemies()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}