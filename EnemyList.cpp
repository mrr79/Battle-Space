//
// Created by mrr on 13/04/23.
//

#include "EnemyList.h"
#include <iostream>

EnemyList::EnemyList()
        : m_head(nullptr), m_size(0)
{}

EnemyList::~EnemyList() {
    // Delete all nodes in the list
    EnemyNode* current = m_head;
    while (current != nullptr) {
        EnemyNode* next = current->getNext();
        delete current;
        current = next;
    }
}

void EnemyList::append(EnemyNode item) {
    EnemyNode* node = new EnemyNode(item);
    if (m_head == nullptr) {
        m_head = node;
    } else {
        EnemyNode* current = m_head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(node);
    }
    m_size++;
    std::cout << "metio un enemigo a lista" << std::endl;
}

void EnemyList::remove(EnemyNode item) {
    if (m_head == nullptr) {
        return;
    }
    if (m_head->getEnemy() == item.getEnemy()) {
        EnemyNode* temp = m_head;
        m_head = m_head->getNext();
        delete temp;
        m_size--;
        return;
    }
    EnemyNode* current = m_head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getEnemy() == item.getEnemy()) {
            EnemyNode* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            m_size--;
            return;
        }
        current = current->getNext();
    }
}

bool EnemyList::buscar(EnemyNode item) {
    if (m_head == nullptr) {
        return false;
    }
    if (m_head->getEnemy() == item.getEnemy()) {
        return true;
    }
    EnemyNode* current = m_head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getEnemy() == item.getEnemy()) {
            return true;
        }
        current = current->getNext();
    }
}

int EnemyList::size() const {
    return m_size;
}

EnemyNode* EnemyList::getHead() const {
    return m_head;
}


void EnemyList::clear() {
    EnemyNode* current = m_head;
    while (current != nullptr) {
        EnemyNode* next = current->getNext();
        delete current;
        current = next;
    }
    m_head = nullptr;
    m_size = 0;
}

void EnemyList::printList() const {
    std::cout << "Enemy List: ";
    EnemyNode* current = m_head;
    while (current != nullptr) {
        std::cout << current->getEnemy() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

EnemyList* EnemyList::duplicate() const {
    EnemyList* newList = new EnemyList();
    EnemyNode* current = m_head;
    while (current != nullptr) {
        Enemy* item = current->getEnemy();
        newList->append(item);
        current = current->getNext();
    }
    return newList;
}