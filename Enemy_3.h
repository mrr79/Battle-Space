//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_ENEMY_3_H
#define BATTLESPACE_ENEMY_3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Collector.h"
#include "Fase.h"

/**
 * @brief La clase Enemy_1 representa a un enemigo de tipo 1 en el juego, ademas se encarga de controlar su movimiento y colisiones con otros objetos
 */
class Enemy_3: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    EnemyList* enemy_list;///< Un puntero a un arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    EnemyList* enemy_list2;///< Un puntero a un segundo arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    int enemy3_life = 2;///< La vida del enemigo 3.
    /**
     * @brief Constructor de la clase Enemy_3.
     * @param collector Objeto Collector que administra el espacio de memoria de las balas.
     * @param enemy_list Array de listas enlazadas de enemigos.
     * @param enemy_list2 Array de listas enlazadas de enemigos.
     *
     * Este constructor crea un objeto Enemy_3 con una posición aleatoria en la pantalla y una imagen asociada. Además, crea un temporizador que se encarga de mover al enemigo por la pantalla.
     */
    Enemy_3(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy3_speed = 5;///< La velocidad del enemigo 3 en el eje x.
    int enemy3_speed_y=5;///< La velocidad del enemigo 3 en el eje x.


public slots:
    /**
    * @brief Función que se encarga de mover al enemigo por la pantalla y verificar si ha recibido daño.
    *
    * Esta función se ejecuta cada vez que el temporizador asociado al enemigo lo indica. La función mueve al enemigo por la pantalla y verifica si ha recibido daño de alguna bala del jugador. Si ha recibido daño suficiente, el enemigo es eliminado del juego.
    */
    void move();
private:
    Collector& collector;
    /**
     * @brief Función que imprime en consola el contenido de enemy_list.
     *
     * Esta función imprime en consola el contenido de enemy_list.
     */
    void printLists() const;
    /**
     * @brief Función que imprime en consola el contenido de enemy_list2.
     *
     * Esta función imprime en consola el contenido de enemy_list2.
     */
    void printLists2() const;

};


#endif //BATTLESPACE_ENEMY_3_H
