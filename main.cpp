#include <QApplication>
#include "Dificulties_Window.h"

Dificulties * difi;
/**
 * @brief Funcion main que inicia el juego desde las pantallas de dificultad
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    difi = new Dificulties();
    difi->show();

    return a.exec();
}
