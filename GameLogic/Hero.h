//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_HERO_H
#define HIROLSY_HERO_H


#include <memory>
#include <vector>
#include "Unit.h"
#include "GameObject.h"
#include "../GUI/ResourcesContainer.h"
#include "Player.h"
#include "Fields/Field.h"

class Player;
class Hero: public GameObject {
    Player* owner;
    double movementPointsMax = 15;
    double currentMovementPoints = 15;
    std::vector<std::shared_ptr<Unit>> units;
public:
    Hero(unsigned int x, unsigned int y, Player *owner) : GameObject(x, y, ResourcesContainer::getInstance().getTexture("hero.png")),
                                                          owner(owner) {
    }

    Player *getOwner() const {
        return owner;
    }
    bool move(Field &field);
};


#endif //HIROLSY_HERO_H
