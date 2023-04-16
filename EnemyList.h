//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYLIST_H
#define BATTLESPACE_ENEMYLIST_H

#include "EnemyNode.h"
#include "Enemy_1.h"
#include "Enemy_2.h"
class EnemyList {
public:
    EnemyList();
    ~EnemyList();

    void append(QGraphicsItem* item);
    void remove(QGraphicsItem* item);
    int size() const;
    EnemyNode* getHead() const;

    void clear();
    void printList() const;
    EnemyList* duplicate() const;

    //void removeEnemy1(Enemy_1* enemy);
private:
    EnemyNode* m_head;
    int m_size;
};


#endif //BATTLESPACE_ENEMYLIST_H
