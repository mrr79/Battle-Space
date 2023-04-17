#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtGlobal>
#include <iostream>
#include <QTimer>
#include "Enemy_2.h"
#include "Enemy_1.h"
#include "Enemy.h"
#include "NodeC.h"
#include "Collector.h"
#include <iostream>
#include "Easy_game.h"
#include "Bullet.h"
#include <QtCore>
#include "Normal_Game.h"
#include "Strategy.h"
#include <iostream>
#include <iostream>
#include <QtXml>
#include <thread>

using namespace std;


Strategy Player::cargar_xml(QString n){
    QFile file(n);
    QString fname = file.fileName();
    qDebug() << "Name:" << fname;
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Failed to open file:" << file.fileName();
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qCritical() << "Failed to parse XML from file:" << file.fileName();
    }

    QDomElement root = doc.documentElement();
    QDomNodeList powers = root.elementsByTagName("power");

    QDomElement power1 = powers.at(0).toElement();
    QString name1 = power1.attribute("name");
    QString description1 = power1.firstChild().toElement().text();
    QString effect1 = power1.lastChild().toElement().text();

    Power *Poder1 = new Power(name1.toStdString(), description1.toStdString(), effect1.toFloat());

    std::cout<<"Name: " << Poder1->getName() <<std::endl;
    std::cout<<"Description: " << Poder1->getDescription()<<std::endl;
    std::cout<<"Effect: " << Poder1->getEffect() <<std::endl;


    QDomElement power2 = powers.at(1).toElement();
    QString name2 = power2.attribute("name");
    QString description2 = power2.firstChild().toElement().text();
    QString effect2 = power2.lastChild().toElement().text();

    Power *Poder2 = new Power(name2.toStdString(), description2.toStdString(), effect2.toFloat());


    std::cout<<"Name: " << Poder2->getName() <<std::endl;
    std::cout<<"Description: " << Poder2->getDescription()<<std::endl;
    std::cout<<"Effect: " << Poder2->getEffect() <<std::endl;

    Strategy strategy(fname.toStdString(), *Poder1, *Poder2);

    std::cout<<"Nombre del poder 1 de estrategia: " << strategy.getPower1().getName() <<std::endl;

    return strategy;
}

bool Player::verificar_si_hay_poder(QString poder, Strategy strategies[]){
    bool exists = false;
    if (strategies[0].getPower1().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[0].getPower2().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[1].getPower1().getName() == poder.toStdString()){
        exists = true;
    }
    if (strategies[1].getPower2().getName() == poder.toStdString()){
        exists = true;
    }
    std::cout<<"Existe: " << exists <<std::endl;
    return exists;
}

void Player::utilizar_poder(QString poder, Strategy strategies[]){
    verificar_si_hay_poder(poder, strategies);
    if (verificar_si_hay_poder(poder, strategies) == 0){
        std::cout << "                                      Esperando 5 segundos..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));


        std::cout<<"                       ESTA ESPERANDO LOS 5 SEGUNDOS "  <<std::endl;

        if (poder == "Poder1" || poder == "Poder2"){
            strategies[0] = cargar_xml("XML/Estrategia1.xml");
        }
        if (poder == "Poder3" || poder == "Poder4"){
            strategies[0] = cargar_xml("XML/Estrategia2.xml");
            std::cout<<"strategies actualizado" << std::endl;
        }
        if (poder == "Poder5" || poder == "Poder6"){
            strategies[0] = cargar_xml("XML/Estrategia3.xml");
        }
        if (poder == "Poder7" || poder == "Poder8"){
            strategies[0] = cargar_xml("XML/Estrategia4.xml");
        }
        std::cout<<"Cambio de XML" <<std::endl;
    }
    verificar_si_hay_poder(poder, strategies);
    if  (poder == "Poder1"){
        Poder1 = 2;
    }
    if  (poder == "Poder2"){
        Poder2 = 2;
    }
    if  (poder == "Poder3"){
        Poder3 = 2;
    }
    if  (poder == "Poder4"){
        Poder4 = 2;
    }
    if  (poder == "Poder5"){
        Poder5 = 2;
    }
    if  (poder == "Poder6"){
        Poder6 = 2;
    }
    if  (poder == "Poder7"){
        Poder7 = 2;
    }
    if  (poder == "Poder8"){
        Poder8 = 2;
    }

}



// mover jugador arriba y abajo
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up){
        std::cout <<"ESTADO DE PODER:" << Poder1 << std::endl;
        if (Poder1 == 2){
            std::cout <<"PODER ACTIVADO" << std::endl;
            if (pos().y() > 0){
                setPos(x(),y()-50);
            }
        }
        else {
            if (pos().y() > 0){
                setPos(x(),y()-10);
            }
        }



    }
    else if (event->key() == Qt::Key_Down) {
        std::cout <<"ESTADO DE PODER:" << Poder1 << std::endl;

        if (Poder1 == 2){
            std::cout <<"PODER ACTIVADO" << std::endl;
            if (pos().y() < 500) {
                setPos(x(), y() + 50);
            }
        } else {
          if (pos().y() < 500) {
              setPos(x(), y() + 10);
          }
        }

    }
    else if (event->key() == Qt::Key_1){
        std::cout << "PODER ACTIVADO" << std::endl;
        utilizar_poder("Poder1", strategies);

    }
    else if (event->key() == Qt::Key_2){
        utilizar_poder("Poder2", strategies);
    }
    else if (event->key() == Qt::Key_3){
        utilizar_poder("Poder3", strategies);
    }
    else if (event->key() == Qt::Key_4){
        utilizar_poder("Poder4", strategies);
    }
    else if (event->key() == Qt::Key_5){
        utilizar_poder("Poder5", strategies);
    }
    else if (event->key() == Qt::Key_6){
        utilizar_poder("Poder6", strategies);
    }
    else if (event->key() == Qt::Key_7){
        utilizar_poder("Poder7", strategies);
    }
    else if (event->key() == Qt::Key_8){
        utilizar_poder("Poder8", strategies);
    }
}



Player::Player(Collector& collector, int bullets_number, int ships_number,  Fase& fase1, Fase& fase2)
        : collector(collector), bullets_number(bullets_number), ships_number(ships_number)
{

    this->bullets_number = bullets_number;
    this->ships_number = ships_number;
    this->fase1=fase1;
    this->fase2=fase2;

    Poder1 = 1;
    Poder2 = 1;
    Poder3 = 1;
    Poder4 = 1;
    Poder5 = 1;
    Poder6 = 1;
    Poder7 = 1;
    Poder8 = 1;


    connect(this, &Player::handleBulletCollision, this, &Player::handleBulletCollision);



    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveBullets);
    timer ->setInterval(50);
    timer -> start();


}


// disparo automatico

void Player::bullets()
{
    if (bullets_number != 0){
        Bullet *bullet = new Bullet();
        collector.insertar_collector((void *) bullet);
        bullet->setPos(x()+100,y()+20);

        // add bullet to the scene
        scene()->addItem(bullet);


        bullets_number--;
    } else {
        //cout << "Se acabaron las balas" << endl;
        if (usedBullets.collector_size() > 0) {
            Bullet *bullets = new Bullet();
            bullets = static_cast<Bullet *>(usedBullets.getHead()->valor);
            usedBullets.elimPos(0);
            bullets->setPos(x(), y());
            collector.insertar_collector((void *) bullets);
        }
    }

}



void Player::handleBulletCollision()
{
    Bullet *bullet = static_cast<Bullet *>(sender());
    if (collector.en_collector((void *) sender())) {
        collector.eliminar_nodo_collector((void *) sender());
    }

}

void Player::moveBullets(){
    //cout << "Se deberia de poder mover la bala: " << endl;
    for (int i = 0; i < collector.collector_size(); i++){
        Bullet* bullet = static_cast<Bullet*>(collector.getPos(i));
        bullet -> setPos(bullet->pos().x() + 10, bullet -> pos().y());
        if (bullet -> pos().x() > 800){
            cout << "SE SALIO " << endl;
            collector.elimPos(i);
            bullet -> reduceDamage();
            usedBullets.insertar_collector((void *) bullet);
        }
    }
}


void Player::spawn_enemies_1()
{
    Enemy_1 *enemy_1 = new Enemy_1(collector, enemy_list, enemy_list2);
    scene()->addItem(enemy_1);
    std::cout << "NUEVO ENEMIGO" << std::endl;
    cout << enemy_1 << endl;
    enemyList.append(reinterpret_cast<Enemy *>(enemy_1));
    std::cout << "NUEVO ENEMIGO" << std::endl;
    enemyList.printList();
}

void Player::spawn_enemies_2()
{
    Enemy_2 *enemy_2 = new Enemy_2(collector, enemy_list, enemy_list2);
    scene()->addItem(enemy_2);
    enemyList.append(reinterpret_cast<Enemy *>(enemy_2));

}

void Player::spawn_random_enemies() {
    num_enemies = 0;
    num_enemies_1 = 0;
    num_enemies_2 = 0;
    reset_powers();

    while (num_enemies < ships_number) {
        std::cout << "round: " << round_aux  << std::endl;
        if (round_aux < 5) {
            if (num_enemies_1 < ships_number && num_enemies_2 < ships_number && qrand() % 2 == 0) {
                QTimer::singleShot((1000 * (num_enemies_2 + num_enemies)), this, [=]() {
                    spawn_enemies_2();
                    num_enemies_2 += 1;
                    if (enemyList.size() == ships_number) {
                        std::cout << "lista llena: revisar si hay 8 pt1" << std::endl;
                        //enemy_list[n] = enemyList;
                        //n++;
                        enemyList.duplicate();
                        enemy_list[n]=*enemyList.duplicate();
                        n++;
                        // emit signal to change the round
                        emit roundChanged();
                        round_aux++;
                        std::cout << "round: " << round_aux  << std::endl;
                        QTimer::singleShot((1000 + (enemyList.size() * 500)), this, [=]() {
                            fase1.get_list(round_aux-1) = enemyList;
                            enemyList.clear();
                            spawn_random_enemies();
                        });
                    }

                });
            } else {
                QTimer::singleShot((1000 * (num_enemies_1 * num_enemies_1 + num_enemies)), this, [=]() {
                    spawn_enemies_1();
                    num_enemies_1 += 1;


                    if (enemyList.size() == ships_number) {
                        //enemy_list[n] = enemyList;
                        //n++;

                        enemyList.duplicate();
                        enemy_list[n]=*enemyList.duplicate();
                        n++;
                        // emit signal to change the round
                        emit roundChanged();
                        round_aux++;
                        QTimer::singleShot((1000 + (enemyList.size() * 500)), this, [=]() {
                            fase1.get_list(round_aux-1) = enemyList;

                            enemyList.clear();
                            spawn_random_enemies();
                        });
                    }
                });
            }
            num_enemies++;

        }
        //round_aux++;
        else{
            std::cout << "---------------------------1---------------------------" << std::endl;
            printLists();
            std::cout << "------------------------------------------------------" << std::endl;
            reset_powers();
            spawn_random_enemies2();
           ;
        }
        }

}

void Player::spawn_random_enemies2() {
    num_enemies = 0;
    num_enemies_1 = 0;
    num_enemies_2 = 0;

    //round_aux++

    while (num_enemies < ships_number) {
        std::cout << "round: " << round_aux2  << std::endl;
        if (round_aux2 < 5) {
            if (num_enemies_1 < ships_number && num_enemies_2 < ships_number && qrand() % 2 == 0) {
                QTimer::singleShot((1000 * (num_enemies_2 + num_enemies)), this, [=]() {
                    spawn_enemies_2();
                    num_enemies_2 += 1;


                    if (enemyList.size() == ships_number) {
                        std::cout << "lista llena: revisar si hay 8 pt1" << std::endl;
                        enemyList.printList();
                        enemyList.duplicate();
                        enemy_list2[m]=*enemyList.duplicate();
                        m++;
                        // emit signal to change the round
                        emit roundChanged();
                        round_aux2++;
                        std::cout << "round: " << round_aux  << std::endl;
                        QTimer::singleShot((1000 + (enemyList.size() * 500)), this, [=]() {
                            //  QUE GUARDE ENEMYLIST EN OTRA LISTA: OLEADA[I]1
                            fase2.get_list(round_aux2-1) = enemyList;
                            enemyList.clear();
                            std::cout << "lista vacia: revisar si hay 0 pt2" << std::endl;
                            enemyList.printList();
                            spawn_random_enemies2();
                        });
                    }

                });
            } else {
                QTimer::singleShot((1000 * (num_enemies_1 * num_enemies_1 + num_enemies)), this, [=]() {
                    spawn_enemies_1();
                    num_enemies_1 += 1;


                    if (enemyList.size() == ships_number) {
                        std::cout << "lista llena: revisar si hay 8 pt2" << std::endl;
                        enemyList.printList();
                        enemyList.duplicate();
                        enemy_list2[m]=*enemyList.duplicate();
                        m++;
                        // emit signal to change the round
                        emit roundChanged();
                        round_aux2++;
                        std::cout << "round: " << round_aux  << std::endl;
                        QTimer::singleShot((1000 + (enemyList.size() * 500)), this, [=]() {
                            fase2.get_list(round_aux2-1) = enemyList;
                            enemyList.clear();
                            std::cout << "lista vacia: revisar si hay 0 pt2" << std::endl;
                            enemyList.printList();
                            spawn_random_enemies2();
                        });
                    }
                });
            }
            num_enemies++;

        }
            //round_aux++;
        else{
            std::cout << "---------------------------2---------------------------" << std::endl;
            printLists2();
            std::cout << "------------------------------------------------------" << std::endl;
            break;
        }
    }

}


void Player::spawn_enemies()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::printLists() const {
    std::cout << "Enemy Lists: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "List " << i+1 << ": ";
        EnemyNode* current = enemy_list[i].getHead();
        while (current != nullptr) {
            std::cout << current->getEnemy() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
}
void Player::printLists2() const {
    std::cout << "Enemy Lists2: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "List " << i+1 << ": ";
        EnemyNode* current = enemy_list2[i].getHead();
        while (current != nullptr) {
            std::cout << current->getEnemy() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
}

void Player::reset_powers() {
    Poder1 = 1;
    Poder2 = 1;
    Poder3 = 1;
    Poder4 = 1;
    Poder5 = 1;
    Poder6 = 1;
    Poder7 = 1;
    Poder8 = 1;
}

int Player::getPoder2() {
    return Poder2;
}