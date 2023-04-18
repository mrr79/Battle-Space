//
// Created by mrr on 16/04/23.
//

#ifndef BATTLESPACE_WIN_WINDOW_H
#define BATTLESPACE_WIN_WINDOW_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
/**
 *  @brief Declaracion de la clase Win_Window
 */
class Win_Window: public QGraphicsView{
public:
    /**
     * @brief Metodo que hace aparecer a la ventana de ganar y coloca un boton para regresar al menu de inicio
     * @param parent
     */
    Win_Window(QWidget * parent=0);
    /**
     * @brief Metodo que pone en escena la pantalla de dificultades
     */
    void main_menu();

    QGraphicsScene * scene;
};

#endif //BATTLESPACE_WIN_WINDOW_H
