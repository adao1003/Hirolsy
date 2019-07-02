//
// Created by adao1003 on 6/19/19.
//

#include "Mountains.h"

Mountains::Mountains() : Field(std::numeric_limits<double>::max(), sf::Vector2i(128, 0)) {}

void Mountains::resetCost() {
    cost = std::numeric_limits<double>::max();
}

Field *Mountains::clone() {
    return new Mountains(*this);
}
