#ifndef BATTLESPACE_FASE_H
#define BATTLESPACE_FASE_H

#include "EnemyList.h"
/**
 * @brief declaracion de la calase fase
 */
class Fase {
public:
    /**
     * @brief Inicializacion de la clase fase creando un arreglo
     */
    Fase();
    /**
     * @brief Obtiene la lista especifica de una fase
     * @param index
     * @return
     */
    EnemyList& get_list(int index); // return reference to an EnemyList object in the fase array
private:
    EnemyList* fase[5]; // array of EnemyList pointers
};

#endif //BATTLESPACE_FASE_H
