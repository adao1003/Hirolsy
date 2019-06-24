//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_TOWN_H
#define HIROLSY_TOWN_H


#include "GameObject.h"
class Player;
class Town: public GameObject {
    Town() : GameObject(0, 0, sf::Texture()) {}

    Player* owner = nullptr;
};


#endif //HIROLSY_TOWN_H
