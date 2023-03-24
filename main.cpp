#include <iostream>
#include <QApplication>
#include "ship.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // Create an item to add to the scene
    MyShip *player = new MyShip();
    scene->addItem(player);

    // Make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Create a view to visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Set the size of the view
    view->setFixedSize(800, 600);

    // Set the scene rect
    scene->setSceneRect(0, 0, 800, 600);

    // Spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // Show the view
    view->show();

    return a.exec();
}
