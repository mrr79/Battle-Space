//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYLIST_H
#define BATTLESPACE_ENEMYLIST_H

#include "EnemyNode.h"
/**
 * @brief Clase EnemyNode para la lista enlazada de enemigos.
 *
 * Esta clase hace una lista enlazada de enemigos, que contiene
 * un puntero a un objeto Enemy y un puntero al siguiente nodo de la lista.
 */
class EnemyList {
public:
    EnemyList();
    ~EnemyList();
    /**
        * @brief Agrega un nuevo enemigo a la lista.
        * @param EnemyNode Objeto Enemy que se va a agregar a la lista.
        */
    void append(EnemyNode item);
    /**
    * @brief Elimina un enemigo de la lista.
    * @param EnemyNode Objeto Enemy que se va a eliminar de la lista.
    */
    void remove(EnemyNode item);
    /**
        * @brief Busca un enemigo en la lista.
        * @param EnemyNode Objeto Enemy que se va a buscar en la lista.
        * @return Verdadero si el objeto Enemy se encuentra en la lista, falso en caso contrario.
        */
    bool buscar(EnemyNode item);
    /**
    * @brief Obtiene el número de elementos en la lista.
    * @return Número de elementos en la lista.
    */
    int size() const;
    /**
    * @brief Este método devuelve el nodo inicial de la lista.
    * @return Devuelve un puntero a EnemyNode que representa el primer nodo de la lista.
    */
    EnemyNode* getHead() const;
    /**
    * @brief Este método borra todos los nodos de la lista y establece el tamaño de la lista a cero.
    */
    void clear();
    /**
    * @brief Este método imprime los elementos de la lista en la consola.
    */
    void printList() const;
    /**
   * @brief Este método devuelve una nueva lista que es una copia de la lista actual.
   * @return Devuelve un puntero a EnemyList que representa la nueva lista.
   */
    EnemyList* duplicate() const;
private:
    EnemyNode* m_head;
    int m_size;


};


#endif //BATTLESPACE_ENEMYLIST_H
