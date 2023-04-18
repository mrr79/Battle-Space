//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_POWER_H
#define BATTLESPACE_POWER_H


#include <string>
/**
 * @brief Dclaracion de la clase Power
 */
class Power {
public:
    /**
     * @brief Constructor de la clase power con su nombre, descripcion y efecto
     * @param n
     * @param d
     * @param e
     */
    Power(std::string n, std::string d, float e);
    /**
     * @brief Metodo que obtiene el nombre del poder
     * @return
     */
    std::string getName() const;
    /**
     * @brief Metodo que obtiene la descripcion del poder
     * @return
     */
    std::string getDescription() const;
    /**
     * @brief Metodo que obtiene el efecto del poder
     * @return
     */
    float getEffect() const;
    /**
     * @brief Metodo que modifica el nombre del poder
     * @param n
     */
    void setName(std::string n);
    /**
     * @brief Metodo que modifica la descripcion de poder
     * @param d
     */
    void setDescription(std::string d);
    /**
     * @brief Metodo que modifica el efecto del poder
     * @param e
     */
    void setEffect(float e);

private:
    std::string name;
    std::string description;
    float effect;
};


#endif //BATTLESPACE_POWER_H
