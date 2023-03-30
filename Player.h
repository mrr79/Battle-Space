#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int bullets_number;
    void keyPressEvent(QKeyEvent * event);
    Player(int bullets_number);
public slots:
    void bullets();
    void spawn_enemies_1();
    void spawn_enemies_2();
    void spawn_enemies();
};
#endif // PLAYER_H
