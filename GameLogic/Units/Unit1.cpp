//
// Created by adao1003 on 7/2/19.
//

#include "Unit1.h"
#include "../../GUI/ResourcesContainer.h"

Unit1::Unit1(Player *owner) : Unit(sf::Sprite(ResourcesContainer::getInstance().getTexture("Unit1.png")), 6, 7, 5, 4, owner) {
}
