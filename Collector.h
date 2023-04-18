//
// Created by mrr on 30/03/23.
//

#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "NodeC.h"
#include <iostream>
/**

* @brief La clase Collector se utiliza para la recolección de balas que no impactan enimigos en una lista enlazada simple, con el fin de utilizarlas nuvamente.
*
*/
class Collector{
private:
    /**
     * brief Método privado utilizado para insertar un nodo tipo bala en la lista del collector.
     * @param cabeza Puntero a la cabeza de la lista enlazada simple.
     * @param valor Puntero al valor del nodo a insertar.
     */
    void insertar_collector_private(NodeC *&cabeza, void *valor);

    /**

@brief Método privado utilizado para mostrar la lista del collector.
@param cabeza Puntero a la cabeza de la lista enlazada simple.
*/
    void mostrar_collector_private(NodeC *cabeza);
    void eliminar_collector(void *valor);
public:
    /**
* @brief Constructor de la clase Collector.
*/
    Collector();  // constructor

    /**
 * @brief Método utilizado para insertar un nodo en la lista del collector.
 * @param valor Puntero al valor del nodo a insertar.
 */
    /**
    * @brief Método utilizado para eliminar un nodo de la lista del collector.
    * @param valor Puntero al valor del nodo a eliminar.
    */
    void eliminar_nodo_collector(void* valor);

    /**
 * @brief Método utilizado para obtener el tamaño de la lista del collector.
 * @return Tamaño de la lista del collector.
 */
    int collector_size();

    /**
* @brief Método utilizado para comprobar si un valor se encuentra en la lista del collector.
* @param valor Puntero al valor a comprobar.
* @return Verdadero si el valor se encuentra en la lista del collector, falso en caso contrario.
*/
    bool en_collector(void *valor);
/**
 * @brief Método utilizado para obtener el primer valor de la lista del collector.
 * @return Puntero al primer valor de la lista del collector.
 */
    void* get_first_collector();
/**
 * @brief Método utilizado para obtener el valor de un nodo en una posición determinada de la lista del collector.
 * @param posicion Posición del nodo cuyo valor se desea obtener.
 * @return Puntero al valor del nodo en la posición especificada.
 */
    void *getPos(int posicion);
/**
 * @brief Método utilizado para eliminar el nodo en una posición determinada de la lista del collector.
 * @param posicion Posición del nodo a eliminar.
 */
    void elimPos(int pos);
/**
 * @brief Método utilizado para obtener el puntero al primer nodo de la lista enlazada simple.
 * @return Puntero al primer nodo de la lista enlazada simple.
 */
    NodeC *getHead();
/**
 * @brief Método utilizado para comprobar si la lista del collector contiene nodos.
 * @return Verdadero si la lista del collector contiene nodos, falso en caso contrario.
 */
    bool validar_existencia();
/**
 * @brief Inserta un elemento en el colector.
 *
 * @param valor Valor del elemento a insertar.
 */
    void insertar_collector(void *valor);
/**
 * @brief Obtiene el valor del primer elemento del colector.
 *
 * @return Puntero al valor del primer elemento del colector.
 */
    void* obtener_valor ();

    /**
 * @brief Muestra por consola los valores almacenados en el colector.
 */
    void mostrar_collector();



    NodeC *inicio = nullptr;
    //~Collector(); // destructor



};

#endif