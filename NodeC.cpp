//
// Created by mrr on 30/03/23.
//
#include <iostream>
#include "NodeC.h"


NodeC::NodeC(void){
    this->valor = NULL;
    this->next = NULL;
}

NodeC::NodeC(void* valor){
    this->valor = valor;
    this->next = NULL;
}

void* NodeC::obtener_valor(){
    std::cout<<"EL valor almacenado es: " << valor <<std::endl;
    return valor;
}