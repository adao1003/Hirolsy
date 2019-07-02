//
// Created by adao1003 on 6/19/19.
//

#include "Unit.h"

const sf::Sprite &Unit::getSprite() const {
    return sprite;
}

void Unit::setSprite(const sf::Sprite &sprite) {
    Unit::sprite = sprite;
}

Unit::Unit(const sf::Sprite &sprite, unsigned int hp, unsigned int attack, unsigned int defense, unsigned int speed,
           Player *owner) : sprite(sprite), HP(hp), atc(attack), defense(defense),
                            Speed(speed), owner(owner) {
    currentMove = speed;
}

void Unit::setPoz(unsigned _x, unsigned _y) {
    x=_x;
    y=_y;
    sprite.setPosition(x*64,y*64);
}

unsigned int Unit::getX() const {
    return x;
}

unsigned int Unit::getY() const {
    return y;
}

void Unit::setX(unsigned int x) {
    Unit::x = x;
    sprite.setPosition(x*64,y*64);
}

void Unit::setY(unsigned int y) {
    Unit::y = y;
    sprite.setPosition(x*64,y*64);
}

bool Unit::move() {
    if(currentMove==0)
        return false;
    else {
        currentMove--;
        return true;
    }

}

void Unit::attack(Unit &target) {
    target.HP-=(atc-target.defense);
    currentMove=0;
}

void Unit::resetMove() {
    currentMove = Speed;
}

bool Unit::isDead() {
    return HP<=0;
}

unsigned int Unit::getCurrentMove() const {
    return currentMove;
}

Player *Unit::getOwner() const {
    return owner;
}

