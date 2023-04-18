#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Collector.h"
#include "Player.h"
#include "Enemy_1.h"



#include <QGraphicsRectItem>
#include <QObject>

/**
* @brief Clase que representa una bala disparada por el jugador
*
* Esta clase define el comportamiento de las balas disparadas por el jugador.
* Las balas se mueven hacia la derecha a una velocidad constante y desaparecen cuando salen de la escena.
* También pueden infligir daño a los enemigos con los que colisionan.
*/
class Bullet: public QObject ,public QGraphicsPixmapItem{

    Q_OBJECT
public:
    /**
    * @brief Constructor por defecto de la clase Bullet
    *
    * Crea una nueva instancia de la clase Bullet y establece la imagen de la bala.
    */
    Bullet();

    /**
     * @brief Mueve la bala hacia la derecha en la escena
     *
     * Mueve la bala hacia la derecha en la escena a una velocidad constante. Si la bala
     * sale de la escena, se elimina automáticamente.
     */
    Collector *collector = new Collector();
    double bullet_damage; ///< Daño infligido por la bala a los enemigos
public slots:
    /**
     * @brief Maneja las colisiones de la bala con otros elementos de la escena
     *
     * Maneja las colisiones de la bala con otros elementos de la escena, como los enemigos.
     * Si la bala choca con un enemigo, se emite una señal para indicar que se ha detectado una colisión.
     */
    void move();

    /**
     * @brief Reduce el daño infligido por la bala
     *
     * Reduce el daño infligido por la bala en un 20%. Esto se utiliza para simular el efecto de la
     * atenuación de la bala a medida que se reutiliza en el collector.
     */
    void reduceDamage();

signals:
    /**
     * @brief Señal emitida cuando se detecta una colisión con un enemigo
     *
     * Esta señal se emite cuando la bala colisiona con un enemigo en la escena.
     */
    void collisionDetected();

protected slots:
    void handleCollision();
//public signals:
    //void positionOutOfRange();
};

#endif // BULLET_H

