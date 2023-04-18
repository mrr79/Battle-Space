//
// Created by mrr on 29/03/23.
//

#ifndef BATTLESPACE_GAME_OVER_H
#define BATTLESPACE_GAME_OVER_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

/**
 * @brief La clase Game_Over representa la ventana que se muestra cuando el juego termina.
 *
 * Esta clase hereda de QGraphicsView y es responsable de mostrar la escena de Game Over. En esta ventana, el usuario puede
 * elegir volver a la pantalla principal del juego.
 *
 */
class Game_Over: public QGraphicsView{
public:
    /**
     * @brief Constructor de Game_Over.
     *
     * Este constructor crea la escena de Game Over y configura los elementos que se muestran en ella, incluyendo el título,
     * el botón para volver al menú principal y la conexión con la señal correspondiente para procesar la selección del usuario.
     *
     * @param parent El padre de la vista.
     */
    Game_Over(QWidget * parent=0);

    /**
     * @brief Slot para volver al menú principal.
     *
     * Este slot es llamado cuando el usuario hace clic en el botón para volver al menú principal. Cierra la ventana actual y
     * muestra la ventana de selección de dificultad del juego.
     *
     */
    void main_menu();

    QGraphicsScene * scene;
};


#endif //BATTLESPACE_GAME_OVER_H
