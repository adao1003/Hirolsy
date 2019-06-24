//
// Created by adao1003 on 6/24/19.
//

#include "Quarry.h"
#include "../../GUI/ResourcesContainer.h"

Quarry::Quarry(unsigned int x, unsigned int y) : Mine(x, y, ResourcesContainer::getInstance().getTexture("quarry.png")) {}
