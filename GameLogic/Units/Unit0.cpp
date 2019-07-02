//
// Created by adao1003 on 7/2/19.
//

#include "Unit0.h"
#include "../../GUI/ResourcesContainer.h"

Unit0::Unit0(Player *owner) : Unit(sf::Sprite(ResourcesContainer::getInstance().getTexture("Unit0.png")), 5, 6, 3, 4, owner) {
}
