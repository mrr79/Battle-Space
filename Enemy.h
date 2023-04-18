#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
/**
 * @brief declaracion de la clase padre de tipo enemigo
 */
class Enemy: public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    /**
     * @brief Inicializa la clase enemigo
     */
    Enemy();
public slots:
    /**
     * @brief Metodo que permite el movimiento del enemigo en el eje x
     */
    void move();
    /**
     * @brief Metodo que permite el movimiento del enemigo en y
     */
    void move_y();
};

#endif // ENEMY_H
