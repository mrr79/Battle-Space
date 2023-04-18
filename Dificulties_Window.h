#ifndef DIFICULTIES_WINDOW_H
#define DIFICULTIES_WINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

/**
 * @brief La clase Dificulties_Window representa la ventana que permite al jugador elegir la dificultad del juego.
 *
 * Esta clase es responsable de crear y mostrar los elementos necesarios para mostrar la ventana de selección de dificultad,
 * así como de manejar los eventos generados por los botones que permiten al jugador iniciar una nueva partida.
 */
class Dificulties: public QGraphicsView{
public:
    /**
 * @brief Constructor de la clase Dificulties que crea la escena y configura los botones para cada nivel de dificultad.
 * @param parent Puntero al widget padre.
 */
    Dificulties(QWidget * parent=0);
/**
 * @brief Método que inicia el juego en modo fácil.
 */
    void easy();
    /**
 * @brief Método que inicia el juego en modo normal.
 */
 void normal();
    /**
    * @brief Método que inicia el juego en modo difícil.
    */
    void hard();

    QGraphicsScene * scene;
};

#endif // DIFICULTIES_WINDOW_H