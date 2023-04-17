//
// Created by mrr on 16/04/23.
//

#include "Strategy.h"
#include "Power.h"


Strategy::Strategy(std::string n, Power p1, Power p2)
        : name(n), power1(p1), power2(p2)
{
}

std::string Strategy::getName() const {
    return name;
}

void Strategy::setName(std::string n) {
    name = n;
}

Power Strategy::getPower1() const {
    return power1;
}

void Strategy::setPower1(Power p) {
    power1 = p;
}

Power Strategy::getPower2() const {
    return power2;
}

void Strategy::setPower2(Power p) {
    power2 = p;
}