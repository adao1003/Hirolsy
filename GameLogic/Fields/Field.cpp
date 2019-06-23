//
// Created by adao1003 on 6/19/19.
//

#include "Field.h"

Field::Field(double cost, const sf::Vector2i &offset) : cost(cost),
                                                        offset(offset) {}

const sf::Vector2i &Field::getOffset() const {
    return offset;
}
