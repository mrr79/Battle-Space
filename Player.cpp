//
// Created by mrr on 24/03/23.
//
#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy_2.h"
#include "Enemy_1.h"

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

void Player::bullets()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+100,y()+20);
    scene()->addItem(bullet);

}

void Player::spawn_enemies1(){
    Enemy_1 *enemy_1 = new Enemy_1();
    scene()->addItem(enemy_1);
    //show();
}

void Player::spawn_enemies2()
{
    Enemy_2 *enemy_2 = new Enemy_2();
    scene()->addItem(enemy_2);
    //show();
}