//
// Created by mrr on 30/03/23.
//
#include <iostream>
#include "Collector.h"
#include "NodeC.h"
#include <iostream>
using namespace std;
NodeC *inicio = NULL;

void Collector::insertar_collector_private(NodeC* &cabeza, void* valor){
    NodeC *nuevo_nodo = new NodeC(valor);

    NodeC *aux = cabeza;

    cabeza = nuevo_nodo;
    cabeza->next = aux;
}

NodeC* Collector::getHead() {
    return inicio;
}

void Collector::eliminar_nodo_collector(void* valor) {
    NodeC* current = inicio;
    NodeC* prev = NULL;
    while (current != NULL) {
        if (current->valor == valor) {
            if (prev == NULL) {
                // current node is the head of the list
                inicio = current->next;
            } else {
                // current node is not the head of the list
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
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

void* Collector::get_first_collector() {
    if (inicio != NULL) {
        return inicio->valor;
    }
    else {
        std::cout << "Collector is empty" << std::endl;
        return nullptr;
    }
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

bool Collector::en_collector(void *valor) {
    NodeC *current = inicio;
    while (current != NULL) {
        if (current->valor == valor) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void* Collector::getPos(int posicion){
    NodeC *actual = inicio;
    int contador = 0;

    while(actual != NULL){
        if (contador == posicion){
            return actual -> valor;
        }
        actual = actual -> next;
        contador++;
    }
    //cout << "No se encontro valor en esa posicion" << endl;
    //return nullptr;
    if (actual == nullptr){
        return inicio -> valor;
    }
    return actual -> valor;
}

void Collector::elimPos(int posicion){
    NodeC* current = inicio;
    NodeC* prev = NULL;
    int contador = 0;

    while (current != NULL) {
        if (contador == posicion) {
            if (prev == NULL) {
                // current node is the head of the list
                inicio = current->next;
            } else {
                // current node is not the head of the list
                prev->next = current->next;
            }
            void* valor = current->valor;
            delete current;
            std::cout << "Node with value " << valor << " deleted from collector at position " << posicion << std::endl;
            return;
        }
        prev = current;
        current = current->next;
        contador++;
    }
    std::cout << "Node at position " << posicion << " not found in collector" << std::endl;
}

Collector::Collector() {

}
