//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_UNIT_H
#define HIROLSY_UNIT_H


#include <SFML/Graphics/Sprite.hpp>
#include "../Player.h"

class Unit {
protected:
    Player* owner;
    unsigned x = 0;
    unsigned y = 0;
    sf::Sprite sprite;
    int HP;
    unsigned int atc;
    unsigned int defense;
    unsigned int Speed;
    unsigned int currentMove;
public:
    Unit(const sf::Sprite &sprite, unsigned int hp, unsigned int attack, unsigned int defense, unsigned int speed,
         Player *owner);

    const sf::Sprite &getSprite() const;
    void setSprite(const sf::Sprite &sprite);
    void setPoz(unsigned _x, unsigned _y);

    void setX(unsigned int x);

    void setY(unsigned int y);

    unsigned int getX() const;

    unsigned int getY() const;
    bool move();
    void attack(Unit& target);
    void resetMove();
    bool isDead();

    Player *getOwner() const;

    unsigned int getCurrentMove() const;
};


#endif //HIROLSY_UNIT_H