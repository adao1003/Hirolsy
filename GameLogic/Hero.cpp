//
// Created by adao1003 on 6/19/19.
//

#include "Hero.h"

bool Hero::move(Field &field) {
    if(currentMovementPoints-field.getCost()<0)
        return false;
    else{
        currentMovementPoints-=field.getCost();
        return true;
    }
}

void Hero::resetMove() {
    currentMovementPoints=movementPointsMax;
}

Player *Hero::getOwner() const {
    return owner;
}

bool Hero::addUnit(std::shared_ptr<Unit> unit) {
    if(units.size()<maxUnits)
    {
        units.push_back(unit);
        return true;
    }
    return false;
}

const std::vector<std::shared_ptr<Unit>> &Hero::getUnits() const {
    return units;
}
