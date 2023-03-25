//
// Created by mrr on 24/03/23.
//

#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

Player::Player()
{
    setPixmap(QPixmap(":/images/myship.png").scaled(50,50));
}


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

void Player::spawn_enemies(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}