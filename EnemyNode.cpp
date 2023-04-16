//
// Created by mrr on 13/04/23.
//

#include "EnemyNode.h"
#include "Enemy.h"

EnemyNode::EnemyNode(Enemy* enemy)
: m_enemy(enemy), m_next(nullptr)
{}

Enemy* EnemyNode::getEnemy() const {
    return m_enemy;
}

EnemyNode* EnemyNode::getNext() const {
    return m_next;
}

void EnemyNode::setNext(EnemyNode* node) {
    m_next = node;
}