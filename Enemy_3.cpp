//
// Created by mrr on 16/04/23.
//

#include "Enemy_3.h"
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


Enemy_3::Enemy_3(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[])
        : collector(collector), enemy_list(enemy_list), enemy_list2(enemy_list2)
{
    this->enemy_list = enemy_list;
    this->enemy_list2 = enemy_list2;

    int random_number = rand() % 550;
    self_ptr = this; // Asignar la dirección de memoria del objeto actual al puntero self_ptr

    setPos(800,random_number);

    setPixmap(QPixmap(":/Images/E3"));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy_3::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);

            collector.eliminar_nodo_collector(bullet);
            int damage = bullet->bullet_damage;

            if (enemy3_life == 0 && damage==0){
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
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete this;
                emit hitByBullet();
                return;
                std::cout<<"DANO EN LA BALA " << damage <<std::endl;
            }
            else{
                enemy3_life--;
                damage--;
                scene()->removeItem(colliding_items[i]); // Remove bullet from scene
                return;

            }

        }
    }

    // en x y en y
    int new_x = x() - enemy3_speed;
    int new_y = y();

    if (new_x < 0 || new_x > 800) {
        scene()->removeItem(this);
        //delete this;
        return;
    }

    if (new_y < 0) {
        new_y = 0;
    } else if (new_y > 600) {
        new_y = 600;
    } else {
        int random_number = rand() % 2;
        if (random_number == 1){
            new_y -= 20;
        } else {
            new_y += 20;
        }
    }

    setPos(new_x, new_y);
}
void Enemy_3::printLists() const {
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

void Enemy_3::printLists2() const {
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