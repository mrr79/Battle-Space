//
// Created by mrr on 24/03/23.
//


#include "ship.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>
#include <QTimer>
#include <QTimer>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QImage>
#include <QTimer>


MyShip::MyShip()
{
    QPixmap pixmap("/home/mrr/Desktop/Battle-Space/myship.png");
    setPixmap(pixmap.scaled(QSize(50, 50), Qt::KeepAspectRatio));
    setPos(0, scene()->height() / 2 - pixmap.height() / 2);

    // Create a timer to handle automatic shooting
    QTimer* shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &MyShip::shoot);
    shootTimer->start(500);
}

void MyShip::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(), y() - 10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 50 < scene()->height())
            setPos(x(), y() + 10);
    }
}

void MyShip::shoot()
{
    // create a bullet
    Bullet* bullet = new Bullet();
    bullet->setPos(x() + pixmap().width(), y() + pixmap().height() / 2);
    scene()->addItem(bullet);
}


void MyShip::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
