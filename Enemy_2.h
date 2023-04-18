#ifndef RED_ENEMY_H
#define RED_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Player.h"
#include "Collector.h"
#include "EnemyList.h"
/**
 * @brief La clase Enemy_1 representa a un enemigo de tipo 1 en el juego, ademas se encarga de controlar su movimiento y colisiones con otros objetos
 */
class Enemy_2: public QObject , public QGraphicsPixmapItem{
Q_OBJECT
public:
    EnemyList* enemy_list; ///< Un puntero a un arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    EnemyList* enemy_list2;///< Un puntero a un segundo arreglo de listas de enemigos que controla el movimiento de los enemigos en el juego.
    int enemy2_life = 2;///< La vida del enemigo 2.
    /**
    * @brief Constructor de la clase Enemy_2
    * @param collector El recolector de objetos para eliminar los objetos Bullet
    * @param enemy_list Un arreglo de listas enlazadas de enemigos para eliminar este enemigo de la lista
    * @param enemy_list2 Un arreglo de listas enlazadas de enemigos para eliminar este enemigo de la lista
    */
    Enemy_2(Collector& collector, EnemyList enemy_list[], EnemyList enemy_list2[]);
    int enemy2_speed = 5;///< La velocidad del enemigo 2.
public slots:
    /**
     * @brief Función que mueve al enemigo y maneja las colisiones con otros objetos
     *
     * Si colisiona con un objeto de la clase Bullet, reduce la vida del enemigo. Si su vida es cero,
     * elimina el objeto y lo elimina de la lista de enemigos. Si la bala no reduce su vida, solo elimina la bala.
     * Si el enemigo llega al borde izquierdo de la pantalla, lo elimina.
     */
    void move();
private:
    Collector& collector;///< El recolector de balas del juego.
    /**
     * @brief Imprime las listas de enemigos 1 a 5 con los enemigos actuales de cada lista
     *
     * Imprime los enemigos de las listas enemy_list y enemy_list2, para ayudar a depurar y verificar el juego.
     */
    void printLists() const;
    /**
     * @brief Imprime las listas de enemigos 6 a 10 con los enemigos actuales de cada lista
     *
     * Imprime los enemigos de las listas enemy_list y enemy_list2, para ayudar a depurar y verificar el juego.
     */
    void printLists2() const;
};

#endif
