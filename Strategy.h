//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_STRATEGY_H
#define BATTLESPACE_STRATEGY_H


#include <string>
#include "Power.h"
/**
 * @brief Declaracion de la clase estrategia
 */
class Strategy {
public:
    /**
     * @brief Constructor de una clase estrategia que contiene los dos poderes
     * @param n
     * @param p1
     * @param p2
     */
    Strategy(std::string n, Power p1, Power p2);
    /**
     * @brief Metodo que retorna el nombre de la estrategia
     * @return
     */
    std::string getName() const;
    /**
     * Metodo que modifica el nombre de la estrategia
     * @param n
     */
    void setName(std::string n);
    /**
     * @brief Metodo que obtiene el poder 1 de la estrategia
     * @return
     */
    Power getPower1() const;
    /**
     * @brief Metodo que modifica el poder 1 de la estrategia
     * @param p
     */
    void setPower1(Power p);
    /**
     * @brief Metodo que obtiene el poder 2 de la estrategia
     * @return
     */
    Power getPower2() const;
    /**
     * Metodo que modifica el poder 2 de la estrategia
     * @param p
     */
    void setPower2(Power p);

private:
    std::string name;
    Power power1;
    Power power2;
};


#endif //BATTLESPACE_STRATEGY_H
