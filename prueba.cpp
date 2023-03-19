//
// Created by mrr on 19/03/23.
//

#include "prueba.h"
#include <QCoreApplication>
#include <QDebug>

int main (int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << "Hello, Qt!";
    return app.exec();
}
