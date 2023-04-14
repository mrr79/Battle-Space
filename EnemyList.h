//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYLIST_H
#define BATTLESPACE_ENEMYLIST_H

#include "EnemyNode.h"

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
private:
    EnemyNode* m_head;
    int m_size;
};


#endif //BATTLESPACE_ENEMYLIST_H
