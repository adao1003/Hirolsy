//
// Created by adao1003 on 6/24/19.
//

#include "Sawmill.h"
#include "../../GUI/ResourcesContainer.h"

Sawmill::Sawmill(unsigned int x, unsigned int y) : Mine(x, y, ResourcesContainer::getInstance().getTexture("sawmill.png")) {}
