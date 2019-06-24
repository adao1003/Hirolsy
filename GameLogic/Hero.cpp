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
