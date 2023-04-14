//
// Created by mrr on 13/04/23.
//

#include "EnemyNode.h"

EnemyNode::EnemyNode(QGraphicsItem* item)
        : m_item(item), m_next(nullptr)
{}

QGraphicsItem* EnemyNode::getItem() const {
    return m_item;
}

EnemyNode* EnemyNode::getNext() const {
    return m_next;
}

void EnemyNode::setNext(EnemyNode* node) {
    m_next = node;
}