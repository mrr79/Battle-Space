#include "Enemy_1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "Bullet.h"
#include "Collector.h"
#include "NodeC.h"
#include "Player.h"
#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Enemy.h"
#include "NodeC.h"
#include "Collector.h"
#include <iostream>
#include "Easy_game.h"
#include "Bullet.h"
#include <iostream>
#include "Fase.h"
using namespace std;


Enemy_1::Enemy_1(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[])
        : collector(collector), enemy_list(enemy_list), enemy_list2(enemy_list2)
{
    this->enemy_list = enemy_list;
    this->enemy_list2 = enemy_list2;

    int random_number = rand() % 550;
    self_ptr = this; // Asignar la dirección de memoria del objeto actual al puntero self_ptr

    setPos(800,random_number);

    setPixmap(QPixmap(":/Images/e1"));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy_1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);
            cout << "Se borro el malo del collector " << endl;
            cout << this << endl;

            printLists();
            collector.eliminar_nodo_collector(bullet);
            cout << "Se borro el malo del collector " << endl;
            int damage = bullet->bullet_damage;

            if (enemy1_life == 0 && damage==0){
                // remove them both
                cout << "Se va a morir" << this << endl;
                for (int i = 0; i < 5; i++) {
                    if (enemy_list[i].buscar(reinterpret_cast<Enemy *>(this)) == 1) {
                        enemy_list[i].remove(reinterpret_cast<Enemy *>(this));
                        break;
                    }
                    if (enemy_list2[i].buscar(reinterpret_cast<Enemy *>(this)) == 1) {
                        enemy_list2[i].remove(reinterpret_cast<Enemy *>(this));
                        break;
                    }
                }
                printLists();
                printLists2();
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete this;
                emit hitByBullet();
                return;
                std::cout<<"DANO EN LA BALA " << damage <<std::endl;
            }
            else{
                enemy1_life--;
                damage--;
                scene()->removeItem(colliding_items[i]); // Remove bullet from scene
                return;

            }

        }
    }

    /// 5 es la verdadera velocidaD DE LA BALA
    setPos(x() - enemy1_speed,y());
    if (pos().x() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
void Enemy_1::printLists() const {
    std::cout << "Enemy Lists: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "List " << i+1 << ": ";
        EnemyNode* current = enemy_list[i].getHead();
        while (current != nullptr) {
            std::cout << current->getEnemy() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
}

void Enemy_1::printLists2() const {
    std::cout << "Enemy Lists: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "List " << i+1 << ": ";
        EnemyNode* current = enemy_list2[i].getHead();
        while (current != nullptr) {
            std::cout << current->getEnemy() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
}