//
// Created by mrr on 30/03/23.
//
#include <iostream>
#include "Collector.h"
#include "NodeC.h"

NodeC *inicio = NULL;

void Collector::insertar_collector_private(NodeC* &cabeza, void* valor){
    NodeC *nuevo_nodo = new NodeC(valor);

    NodeC *aux = cabeza;

    cabeza = nuevo_nodo;
    cabeza->next = aux;
    std::cout<<"Nuevo puntero ingresado a collector con el valor de: " << valor <<std::endl;
}

void Collector::eliminar_nodo_collector(NodeC* &cabeza){
    if(cabeza != NULL){
        NodeC *aux_eliminar;
        aux_eliminar = cabeza;
        cabeza = cabeza->next;
        delete(aux_eliminar);
        std::cout<<"Primer nodo de Collector eliminado correctamente" << std::endl;
    }
}

void Collector::mostrar_collector_private(NodeC *cabeza){
    NodeC *actual;
    actual = cabeza;
    std::cout<<"Collector actual es: " << std::endl;
    while(actual != NULL){
        std::cout<<actual->valor<<"->";
        actual = actual->next;
    }
}

void Collector::insertar_collector(void *valor){
    std::cout<<"El puntero que se va a insertar a collector es " << valor <<std::endl;
    insertar_collector_private(inicio, valor);
}

bool Collector::validar_existencia(){
    if (inicio != NULL){
        std::cout<<"Collector con nodo(s) restantes" << std::endl;
        return true;
    } else{
        std::cout<<"Collector vacio" << std::endl;
        return false;
    }
}

void* Collector::obtener_valor () {
    void *x = inicio->obtener_valor();
    eliminar_nodo_collector(inicio);
}

int Collector::collector_size() {
    int count = 0;
    NodeC* current = inicio;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}