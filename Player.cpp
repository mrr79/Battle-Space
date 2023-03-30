#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Enemy.h"

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

Player::Player(int bullets_number)
{
    this->bullets_number = bullets_number;
}


void Player::bullets()
{
    if (bullets_number == 0){
        return;
    }
    else{
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+100,y()+20);
        scene()->addItem(bullet);
        bullets_number--;
    }
}

void Player::spawn_enemies_1(){
    Enemy_1 *enemy_1 = new Enemy_1();
    scene()->addItem(enemy_1);
}

void Player::spawn_enemies_2()
{
    Enemy_2 *enemy_2 = new Enemy_2();
    scene()->addItem(enemy_2);
}

void Player::spawn_enemies()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}