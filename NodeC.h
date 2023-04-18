//
// Created by mrr on 30/03/23.
//

#ifndef NODEC_H
#define NODEC_H
/**
 * @brief Declaracion de la clase NodeC
 */
class NodeC{
public:
    /**
     * @brief Inicializa un node de la lista de colector
     */
    NodeC(void);
    void* valor;
    NodeC *next;
    /**
     * @brief Inicializa un node de la lista de colector
     * @param valor
     */
    NodeC (void* valor);
    /**
     * @brief Obtiene el puntero a la bala almacenada en el nodo
     * @return
     */
    void* obtener_valor();
};

#endif

