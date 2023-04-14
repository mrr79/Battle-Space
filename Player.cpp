#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtGlobal>
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
#include <QtCore>
#include "Normal_Game.h"
#include <iostream>
#include <iostream>

using namespace std


;
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

Player::Player(Collector& collector, int bullets_number, int ships_number)
        : collector(collector), bullets_number(bullets_number), ships_number(ships_number)
{
    this->bullets_number = bullets_number;
    this->ships_number = ships_number;
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
    //cout << "Se deberia de poder mover la bala: " << endl;
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
    enemyList.append(enemy_1);
}

void Player::spawn_enemies_2()
{
    Enemy_2 *enemy_2 = new Enemy_2(collector);
    scene()->addItem(enemy_2);
    enemyList.append(enemy_2);

}


void Player::spawn_random_enemies() {
    num_enemies = 0;
    num_enemies_1 = 0;
    num_enemies_2 = 0;

    while (num_enemies < ships_number) {
        if (num_enemies_1 < 4 && num_enemies_2 < 4 && qrand() % 2 == 0) {
            QTimer::singleShot((1000 * (num_enemies_2 + num_enemies)), this, [=](){
            spawn_enemies_2();
                num_enemies_2 +=  1;


                if (enemyList.size() == ships_number) {
                    std::cout << "lista llena: revisar si hay 8 pt1" << std::endl;
                    enemyList.printList();
                    // emit signal to change the round
                    emit roundChanged();
                    QTimer::singleShot((2000+(enemyList.size()*2500)), this, [=]() {
                        enemyList.clear();
                        std::cout << "lista vacia: revisar si hay 0 pt2" << std::endl;
                        enemyList.printList();
                        spawn_random_enemies();
                    });
                }

            });
        } else {
            QTimer::singleShot((1000 * (num_enemies_1*num_enemies_1 + num_enemies)), this, [=]() {
                spawn_enemies_1();
                num_enemies_1 +=  1;


                if (enemyList.size() == ships_number) {
                    std::cout << "lista llena: revisar si hay 8 pt2" << std::endl;
                    enemyList.printList();
                    // emit signal to change the round
                    emit roundChanged();
                    QTimer::singleShot((2000+(enemyList.size()*2500)), this, [=]() {
                        enemyList.clear();
                        std::cout << "lista vacia: revisar si hay 0 pt2" << std::endl;
                        enemyList.printList();
                        spawn_random_enemies();
                    });
                }
            });
        }
        num_enemies++;
    }
}

void Player::spawn_enemies()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}