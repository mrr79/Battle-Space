#ifndef HARD_GAME_H
#define HARD_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>
#include <QTimer>
#include "Player.h"
#include "Fase.h"
/**
 * @brief Clase que define la ventana del juego en modo difícil.
 *
 * Esta clase hereda de QGraphicsView y se encarga de crear la ventana del juego en modo difícil,
 * donde el jugador tendrá menos balas y enemigos más resistentes y rápidos.
 */
class Hard_Game: public QGraphicsView{
Q_OBJECT
public:
    /**
    * @brief Constructor de la clase Hard_Game.
    *
    * @param bullet_speed La velocidad de las balas.
    * @param bullets El número de balas con el que empieza el jugador.
    * @param ships_number El número de naves enemigas que aparecerán en cada ronda.
    * @param health La cantidad de vidas con la que empieza el jugador.
    * @param parent El widget padre de la clase.
    */
    Hard_Game(int bullet_speed,int bullets, int ships_number, int health, QWidget * parent=0);

    //label y timer de los bulllets
    QTimer *timer_bullets = new QTimer;
    //int bullets_number = 150;

    QTimer *check;

    QGraphicsTextItem *bullets_label;
    QGraphicsTextItem *health_label;
    QGraphicsTextItem *round_label;
    QGraphicsTextItem *fase_label;

    QGraphicsTextItem *prueba_label;

    QGraphicsLineItem *line;

    QGraphicsScene * scene;
    //Player * player(collector, bullets_number, ships_number);
    Collector collector;
    Fase fase1;
    Fase fase2;
    //QGraphicsTextItem *collector_label;

    int enemy_count;

    int current_round;

    void add_enemies_to_wave(EnemyList *list_enemies);

public slots:
    /**
    * @brief Método que disminuye el número de balas del jugador.
    *
    * Este método es llamado por un QTimer cada vez que el jugador dispara una bala.
    * Si el número de balas llega a cero y el colector de balas está vacío, el QTimer se detiene.
    *
    */
    void decrease_bullets();

    /**
 * @brief Método que disminuye la salud del jugador.
 *
 * Este método es llamado por un QTimer cada vez que una nave enemiga colisiona con el jugador.
 * Si la salud llega a cero, se llama al método check_health() para determinar si el jugador pierde o gana.
 *
 */
    void decrease_health();

    /**
     * @brief Método que revisa la salud del jugador para determinar si pierde o gana.
     *
     * Este método es llamado por un QTimer cada 50 milisegundos para revisar si la salud del jugador llega a cero.
     * Si la salud llega a cero, se muestra la ventana de Game Over y se cierra la ventana del juego.
     * Si el jugador llega a la ronda 5 en la fase 2 con al menos una vida, se llama al método ganar() para mostrar la ventana de Victoria.
     *
     */
    void check_health();
/**
     * @brief Esta función maneja los cambios en el número de ronda (fase).
     * Cuando el jugador llega al final de una ronda, el número de ronda se incrementa, y se emite la señal spawnEnemies.
     * */
    void handleRoundChanged();
    void emitSpawnEnemiesSignal();
    /**
     * @brief Si el jugador gana la partida, se llama a esta función. Detiene el temporizador de comprobación y abre la Win_Window.
     * */
    void ganar();

private:
    int width = 800;
    int height = 600;
    int bullets_number;
    int health_number;
    int shipsnumber;
    QVector<EnemyList*> wave;
    int round;
    int fase;
    QTimer* timer;
    Player *player;
signals:
    /**
     * @brief Senal enviada cuando aparecen enemigos
     */
    void spawnEnemies();
};

#endif // HARD_GAME_H
