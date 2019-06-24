//
// Created by adao1003 on 6/19/19.
//

#include "Field.h"

Field::Field(double cost, const sf::Vector2i &offset) : cost(cost),
                                                        offset(offset) {}

const sf::Vector2i &Field::getOffset() const {
    return offset;
}

double Field::getCost() {
    double temp;
    try {
        temp = std::get<double>(cost);
    }
    catch (std::bad_variant_access&)
    {
        temp= std::numeric_limits<double>::max();
    }
    return temp;
}

void Field::addBuilding(const std::shared_ptr<GameObject> &ptr) {
    cost = ptr;
}

std::optional<std::shared_ptr<GameObject>> Field::getVisitedObject() {
    std::shared_ptr<GameObject> temp;
    try{
        return std::get<std::shared_ptr<GameObject>>(cost);
    }
    catch (std::bad_variant_access&)
    {
        return {};
    }
}
