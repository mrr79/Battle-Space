#ifndef NORMAL_GAME_H
#define NORMAL_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>
#include <QTimer>
#include "Player.h"
#include "Fase.h"
#include "Player.h"
/**
 * @brief Declaracion de la clase Normal_Game la cual establece las condiciones de juego para la dificultad facil y normal
 */
class Normal_Game: public QGraphicsView{
    Q_OBJECT
public:
    /**
     * @brief Constructor de la clase de juego normal y establece en pantalla las labels con informacon necesaria
     * @param bullet_speed
     * @param bullets
     * @param ships_number
     * @param health
     * @param parent
     */
    Normal_Game(int bullet_speed,int bullets, int ships_number, int health, QWidget * parent=0);

    QTimer *timer_bullets = new QTimer;
    QTimer *check;
    QGraphicsTextItem *bullets_label;
    QGraphicsTextItem *health_label;
    QGraphicsTextItem *round_label;
    QGraphicsTextItem *fase_label;
    QGraphicsLineItem *line;
    QGraphicsScene * scene;
    Collector collector;
    Fase fase1;
    Fase fase2;
    int enemy_count;
    int current_round;
    /**
    * @brief Anade enemigos a la oleada
    * @param list_enemies
    */
    void add_enemies_to_wave(EnemyList *list_enemies);

public slots:
    //ir restando los bullets : ver funcion en el cpp
    /**
     * @brief Va restando la cantidad de bullest mostrada segun se gastan
     */
    void decrease_bullets();
    /**
     * @brief Va restando vida segun pasan los enemigos al jugador y activa el buzzer
     */
    void decrease_health();
    /**
     * @brief Permite checkear la vida para saber si se pierde
     */
    void check_health();
    /**
     * @brief Metodo que cambia de ronda
     */
    void handleRoundChanged();
    /**
     * @brief Emite una senal cuando hay enemigos en pantalla
     */
    void emitSpawnEnemiesSignal();
    /**
     * @brief Metodo que permite poner la ventana de ganar cuando se acaban las rondas
     */
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

#endif // NORMAL_GAME_H
