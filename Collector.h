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

    void mostrar_collector_private(NodeC *cabeza);
    void eliminar_collector(void *valor);
public:
    NodeC *inicio = nullptr;
    void insertar_collector(void *valor);
    bool validar_existencia();
    void* obtener_valor ();
    void mostrar_collector();
    int collector_size();
    void eliminar_nodo_collector(void* valor);
    void* get_first_collector();
    Collector();  // constructor
    //~Collector(); // destructor
    bool en_collector(void *valor);

    void *getPos(int posicion);

    void elimPos(int pos);

    NodeC *getHead();
};

#endif