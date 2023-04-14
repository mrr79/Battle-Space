//
// Created by mrr on 13/04/23.
//

#ifndef BATTLESPACE_ENEMYNODE_H
#define BATTLESPACE_ENEMYNODE_H
#include <QGraphicsItem>


class EnemyNode {
public:
    EnemyNode(QGraphicsItem* item);

    QGraphicsItem* getItem() const;
    EnemyNode* getNext() const;
    void setNext(EnemyNode* node);

private:
    QGraphicsItem* m_item;
    EnemyNode* m_next;
};


#endif //BATTLESPACE_ENEMYNODE_H
