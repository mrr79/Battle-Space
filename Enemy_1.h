#ifndef BLUE_ENEMY_H
#define BLUE_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Collector.h"
#include "Fase.h"
/**
 * @brief La clase Enemy_1 representa a un enemigo de tipo 1 en el juego, ademas se encarga de controlar su movimiento y colisiones con otros objetos
 */
class Enemy_1: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:

    EnemyList* enemy_list; ///< Un puntero a un arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    EnemyList* enemy_list2;///< Un puntero a un segundo arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    /**
     * @brief Constructor de la clase Enemy_1.
     * @param collector El recolector de balas del juego.
     * @param enemy_list Un arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
     * @param enemy_list2 Un segundo arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
     */
    Enemy_1(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy1_life = 1;///< La vida del enemigo 1.
    int enemy1_speed = 10; ///< La velocidad del enemigo 1.
    Enemy_1* self_ptr; ///< Un puntero al objeto actual.

signals:
    /**
     * @brief Señal para indicar que el enemigo ha sido golpeado por una bala.
     */
    void hitByBullet();
public slots:
    /**
     * @brief Método para mover al enemigo.
     */
    void move();
private:

    Collector& collector;///< El recolector de balas del juego.
/**
     * @brief Método para imprimir las listas de enemigos en el primer arreglo.
     */
    void printLists() const;
    /**
     * @brief Método para imprimir las listas de enemigos en el segundo arreglo.
     */
    void printLists2() const;
};


#endif // BLUE_ENEMY_H


