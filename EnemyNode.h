//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYNODE_H
#define BATTLESPACE_ENEMYNODE_H
#include <QGraphicsItem>
#include "Enemy.h"


class EnemyNode {
public:
    EnemyNode(Enemy* enemy);


    Enemy* getEnemy() const;
    EnemyNode* getNext() const;
    void setNext(EnemyNode* node);

private:
    Enemy* m_enemy;
    EnemyNode* m_next;
};


#endif //BATTLESPACE_ENEMYNODE_H
