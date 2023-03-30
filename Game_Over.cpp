//
// Created by mrr on 29/03/23.
//


#include "Game_Over.h"
#include "Dificulties_Window.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include "Game_Over.h"

Game_Over::Game_Over(QWidget *parent)
{
    //Creation of the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    int width = 800;
    int height = 600;

    //Creation and configuration of the title
    QLabel *label = new QLabel("Game Over");
    QGraphicsProxyWidget *proxy_label = new QGraphicsProxyWidget();
    proxy_label->setWidget(label);

    label->setStyleSheet("background-color: white");
    scene->addItem(proxy_label);
    proxy_label->setPos(250, 200);

    //Creaction and configuration of normal mode button
    QPushButton * normal_mode = new QPushButton("BAck to main page");
    normal_mode->setGeometry(0,0,210,70);
    QGraphicsProxyWidget *proxy_normal = new QGraphicsProxyWidget();
    proxy_normal->setWidget(normal_mode);
    scene->addItem(proxy_normal);
    proxy_normal->setPos(285,300);
    connect(normal_mode, &QPushButton::released, this, &Game_Over::main_menu);

    setScene(scene);

    show();
}

void Game_Over::main_menu()
{
    Dificulties *window = new Dificulties();
    window->show();
    this->close();
}
