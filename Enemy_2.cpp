#include "Enemy_2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "Bullet.h"
#include <iostream>
using namespace std;

Enemy_2::Enemy_2(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]) : collector(collector), enemy_list(enemy_list), enemy_list2(enemy_list2)
{
    this->enemy_list = enemy_list;
    this->enemy_list2 = enemy_list2;
    int random_number = rand() % 550;

    setPos(800,random_number);

    setPixmap(QPixmap(":/Images/E2"));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy_2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Bullet)) {
            Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);
            collector.eliminar_nodo_collector(bullet);
            cout << "Se borro el malo otro malo de collector " << endl;
            int damage = bullet->bullet_damage;

            if (enemy2_life == 0 && damage == 0) {
                // remove both bullet and enemy
                for (int i = 0; i < 5; i++) {
                    cout << "Se va a morir" << this << endl;
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
                //delete colliding_items[i];
                scene()->removeItem(this);
                delete this;
                return;
            }
            else {
                enemy2_life--;
                damage--;
                // remove the bullet
                scene()->removeItem(colliding_items[i]);
                return;
            }
        }
    }

    setPos(x() - enemy2_speed, y());
    if (pos().x() < 0) {
        // remove and delete the enemy object
        scene()->removeItem(this);
        delete this;
    }
}
void Enemy_2::printLists() const {
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

void Enemy_2::printLists2() const {
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