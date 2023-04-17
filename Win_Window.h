//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_WIN_WINDOW_H
#define BATTLESPACE_WIN_WINDOW_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Win_Window: public QGraphicsView{
public:
    Win_Window(QWidget * parent=0);

    void main_menu();

    QGraphicsScene * scene;
};

#endif //BATTLESPACE_WIN_WINDOW_H
