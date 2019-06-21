//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_HERO_H
#define HIROLSY_HERO_H


#include <memory>
#include <vector>
#include "Unit.h"

class Hero {
    double movementPointsMax;
    double currentMovementPoints;
    std::vector<std::shared_ptr<Unit>> units;
};


#endif //HIROLSY_HERO_H
