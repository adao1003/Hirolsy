//
// Created by adao1003 on 7/1/19.
//

#ifndef HIROLSY_BATTLEFIELDPART_H
#define HIROLSY_BATTLEFIELDPART_H


#include <memory>
#include "../Units/Unit.h"
#include "../../GUI/ResourcesContainer.h"

class BattleFieldPart {
    std::shared_ptr<Unit> unit;
    sf::Sprite sprite = sf::Sprite(ResourcesContainer::getInstance().getTexture("quarry.png"));
public:
    void addUnit(const std::shared_ptr<Unit> &_unit);
    void removeUnit();
    const sf::Sprite &getSprite() const;
    void setSprite(const sf::Sprite &sprite);

    const std::shared_ptr<Unit> &getUnit() const;
};


#endif //HIROLSY_BATTLEFIELDPART_H
