//
// Created by adao1003 on 6/19/19.
//

#include "Grass.h"

Grass::Grass() : Field(2, sf::Vector2i(64, 0)) {}

void Grass::resetCost() {
    cost = 2;
}

Field *Grass::clone() {
    return new Grass(*this);
}
