//
// Created by adao1003 on 7/1/19.
//

#include <iostream>
#include "BattleFieldPart.h"

void BattleFieldPart::addUnit(const std::shared_ptr<Unit> &_unit) {
    unit = _unit;
    auto temp = _unit->getSprite();
    temp.setPosition(sprite.getPosition());
    std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
    _unit->setSprite(temp);
}

const sf::Sprite &BattleFieldPart::getSprite() const {
    return sprite;
}

void BattleFieldPart::setSprite(const sf::Sprite &sprite) {
    BattleFieldPart::sprite = sprite;
}

const std::shared_ptr<Unit> &BattleFieldPart::getUnit() const {
    return unit;
}

void BattleFieldPart::removeUnit() {
    unit= nullptr;
}

