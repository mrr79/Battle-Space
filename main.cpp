#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyShip myShip;
    myShip.show();
    return app.exec();
}
