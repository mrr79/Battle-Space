//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYNODE_H
#define BATTLESPACE_ENEMYNODE_H
#include <QGraphicsItem>
#include "Enemy.h"

/**
* @brief EnemyNode Esta clase representa un nodo de la lista enlazada de enemigos, que contieneun puntero a un objeto Enemy.
*/
class EnemyNode {
public:
    /**
     * @brief Constructor de EnemyNode.
     * @param enemy Puntero al objeto Enemy asociado con este nodo.
     */
    EnemyNode(Enemy* enemy);

    /**
     * @brief Obtiene el objeto Enemy asociado con este nodo.
     * @return Puntero al objeto Enemy asociado con este nodo.
     */
    Enemy* getEnemy() const;
    /**
     * @brief Obtiene el siguiente nodo de la lista.
     * @return Puntero al siguiente nodo de la lista.
     */
    EnemyNode* getNext() const;
    /**
     * @brief Establece el siguiente nodo de la lista.
     * @param next Puntero al siguiente nodo de la lista.
     */
    void setNext(EnemyNode* node);

private:
    Enemy* m_enemy;  ///< Puntero al objeto Enemy asociado con este nodo.
    EnemyNode* m_next; ///< Puntero al siguiente nodo de la lista.
};


#endif //BATTLESPACE_ENEMYNODE_H
