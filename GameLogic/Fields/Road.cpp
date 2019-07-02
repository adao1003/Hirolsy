//
// Created by adao1003 on 6/19/19.
//

#include "Road.h"

Road::Road() : Field(1, sf::Vector2i(0, 0)) {}

void Road::resetCost() {
    cost =1;
}

Field *Road::clone() {
    return new Road(*this);
}
