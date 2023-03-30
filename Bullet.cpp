#include "Bullet.h"
//#include "Enemy_2.h"
//#include "Enemy_1.h"
#include <QDebug>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Collector.h"
#include "NodeC.h"

Bullet::Bullet()
{
    setPixmap(QPixmap(":/Images/bullet.png").scaled(20,30));

    QTimer *timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

Collector *collector = new Collector();

void Bullet::move() {
    setPos(x() + 15, y());
    if (pos().x() > 800) {
        collector->insertar_collector((void *) this);
        std::cout << "Bullet added to collector" << std::endl;
        //emit positionOutOfRange(); //para el collector
        scene()->removeItem(this);
        //delete this;
    }
}

