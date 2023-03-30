//
// Created by mrr on 30/03/23.
//

#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "NodeC.h"
#include <iostream>

class Collector{
private:
    void insertar_collector_private(NodeC *&cabeza, void *valor);
    void eliminar_nodo_collector(NodeC *&cabeza);
    void mostrar_collector_private(NodeC *cabeza);
public:
    NodeC *inicio = nullptr;
    void insertar_collector(void *valor);
    bool validar_existencia();
    void* obtener_valor ();
    void mostrar_collector();
};

#endif
