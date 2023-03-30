//
// Created by mrr on 30/03/23.
//

#ifndef NODEC_H
#define NODEC_H

class NodeC{
public:
    NodeC(void);
    void* valor;
    NodeC *next;
    NodeC (void* valor);
    void* obtener_valor();
};

#endif

