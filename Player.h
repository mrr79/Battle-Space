#ifndef PLAYER_H
#define PLAYER_H
#include "Collector.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Bullet.h"
#include "EnemyList.h"
#include "Fase.h"
#include "Strategy.h"
#include "Power.h"
#include <QtSerialPort/QSerialPort>
/**
 * @brief Clase player
 */
class Player: public QObject ,public QGraphicsPixmapItem{
Q_OBJECT
public:
    /**
     * @brief Se encarga de buscar los puertos disponibles durante la ejecucion del juego y reconoce el arduino
     */
    void buscaYconectaArduino();
    /**
     * @brief Funcion que permite hacer el buzzer funcionar cada vez que un enemigo cruza la posicion del jugador. Envia una senal al arduino mediante serial
     */
    void on_pushButton_2_clicked();

    int bullets_number;
    /**
     * @brief Funcion que permite reconocer las teclas presionadas y activar el poder correspondiente, ademas es utilizada para el movimiento de la nave con el arduino
     * @param event
     */
    void keyPressEvent(QKeyEvent * event);
    /**
     * @brief Funcion que reinicia el estado de los poderes con el cambio de fase
     */
    void reset_powers();

    int damage = 10;
    Collector collector;
    Collector usedBullets;
    Fase fase1;
    Fase fase2;
/**
 * @brief Constructor de la clase player
 * @param collector Collector que va a ser utilizado para el juego
 * @param bullets_number Numero de balas disponibles para el juego
 * @param ships_number Numero de naves por poner en el juego
 * @param fase1 arreglo de fase
 * @param fase2 arreglo de fase
 */
    Player(Collector& collector, int bullets_number, int ships_number, Fase& fase1, Fase& fase2);
    int size_collector;
    int hits;
    QGraphicsTextItem *collector_label;
    QGraphicsTextItem *hits_label;
    /**
     * @brief Funcion que permite la utillizacion de poderes, realiza la paginacion mediante el cambio de las estrategias segun el arreglo en el que este
     * @param poder
     * @param strategies
     */
    void utilizar_poder(QString poder, Strategy strategies[]);
    /**
     * @brief Permite conocer la existencia de un poder en el arreglo de estrategias para verificar si hay que hacer paginacion
     * @param poder
     * @param strategies
     * @return
     */
    bool verificar_si_hay_poder(QString poder, Strategy strategies[]);
    /**
     * @brief funcion que permite la lectura de los xml y crea una clase estrategia por cada xml ademas de agragarle sus respectivos poderes
     * @param n
     * @return
     */
    Strategy cargar_xml(QString n);


    Strategy strategies[2] = {cargar_xml("XML/Estrategia1.xml"), cargar_xml("XML/Estrategia2.xml")};
    int Poder1;
    int Poder2;
    int Poder3;
    int Poder4;
    int Poder5;
    int Poder6;
    int Poder7;
    int Poder8;

    int Potenciometro;
    int Subir;
    int Bajar;



public slots:
    /**
     * @brief Este metodo crea las bullets en pantalla segun la lista predefinida
     */
    void bullets();
    /**
     * @brief Este metodo permite crear un enemigo de tipo 1 y llama al metodo para ponerlo en escena
     */
    void spawn_enemies_1();
    /**
    * @brief Este metodo permite crear un enemigo de tipo 2 y llama al metodo para ponerlo en escena
    */
    void spawn_enemies_2();
    /**
    * @brief Este metodo permite crear un enemigo de tipo 3 y llama al metodo para ponerlo en escena
    */
    void spawn_enemies_3();
    /**
    * @brief Este metodo permite crear enemigos y llama al metodo para ponerlo en escena
    */
    void spawn_enemies();
    /**
     * @brief este metodo permite el movimiento de las bullets en escena, aqui se configura la velocidad de salida degun el potenciometro
     */
    void moveBullets();
    /**
     * @brief Permite detectar la colision de una bala y un enemigo
     */
    void handleBulletCollision();
    /**
     * @brief Permite poner los enemigos en escena por rondas y guardar cada informacion de ronda en el arreglo de la fase 1
     */
    void spawn_random_enemies();
    /**
     * @brief Permite poner los enemigos en escena por rondas y guardar cada informacion de ronda en el arreglo de la fase 2
     */
    void spawn_random_enemies2();
    /**
    * @brief Permite poner los enemigos en escena por rondas y guardar cada informacion de ronda en el arreglo de la fase 1 para el modo dificil
    */
    void spawn_random_enemies2HARD();
    /**
    * @brief Permite poner los enemigos en escena por rondas y guardar cada informacion de ronda en el arreglo de la fase 2 para el modo dificil
    */
    void spawn_random_enemies_Hard();
    /**
     * @brief Permite imprimir el arreglo de la primera fase
     */
    void printLists() const;
    /**
     * @brief Permite imprimir el arreglo de la segunda fase
     */
    void printLists2() const;


    //void create_new_enemy_lists();
private slots:
    /**
     * @brief permite leer el estado del arduino y obtener el valor del potenciometro y el estado de los botones de subir y bajar
     */
    void on_pushButton_3_clicked();

private:
    EnemyList enemyList;
    int ships_number;
    int num_enemies = 0;
    int num_enemies_1 = 0;
    int num_enemies_2 = 0;
    int num_enemies_3 = 0;
    int round_aux = 0;
    int round_aux2 = 0;
    EnemyList enemy_list[5];
    EnemyList enemy_list2[5];
    int n = 0;
    int m = 0;
    QSerialPort *arduino;
    QTimer* timer;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_UNO = 66;
    static const quint16 arduino_MEGA = 67;
    QString arduino_puerto;
    bool arduino_esta_disponible;
    /**
     * @brief Permite actualizar el estado del 7 segmentos durante la fase 1
     * @param round
     */
    void ssegmentos (int round);
    /**
     * @brief Permite actualizar el estado del 7 segmentos durante la fase 2
     * @param round
     */
    void ssegmentos2 (int round);
    /**
     * @brief Pone al siete segmentos en 5
     */
    void set_5();
    /**
     * @brief Pone al siete segmentos en 4
     */
    void set_4();
    /**
     * @brief Pone al siete segmentos en 3
     */
    void set_3();
    /**
     * @brief Pone al siete segmentos en 2
     */
    void set_2();
    /**
     * @brief Pone al siete segmentos en 1
     */
    void set_1();
    /**
     * @brief Pone al siete segmentos en 0
     */
    void set_0();
    /**
     * Funcion para el movimiento del jugador con el arduino
     */
    void movimiento();
signals:
    /**
     * @brief Emite la senal para cambiar de ronda
     */
    void roundChanged();
    /**
     * Emite la senal para el cambio de ronda en modo dificil
     */
    void roundChangedHARD();


};
#endif // PLAYER_H