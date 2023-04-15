#ifndef BATTLESPACE_FASE_H
#define BATTLESPACE_FASE_H

#include "EnemyList.h"

class Fase {
public:
    Fase();
    EnemyList& get_list(int index); // return reference to an EnemyList object in the fase array
private:
    EnemyList* fase[5]; // array of EnemyList pointers
};

#endif //BATTLESPACE_FASE_H
