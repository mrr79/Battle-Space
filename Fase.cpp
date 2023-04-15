//
// Created by mrr on 14/04/23.
//

#include "Fase.h"

Fase::Fase() {
    // initialize the fase array with new EnemyList objects
    for (int i = 0; i < 5; i++) {
        fase[i] = new EnemyList();
    }
}

EnemyList& Fase::get_list(int index) {
    return *fase[index]; // return a reference to the EnemyList object at the specified index
}
