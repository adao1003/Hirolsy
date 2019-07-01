//
// Created by adao1003 on 6/18/19.
//

#include "Player.h"
#include "Hero.h"
Player::Player(const std::string &name) : name(name) {}

void Player::addTown(std::shared_ptr<Town> ptr) {
    town.emplace_back(ptr);
}

void Player::addHero(std::shared_ptr<Hero> ptr) {
    heroes.emplace_back(ptr);
}

void Player::addMine(std::shared_ptr<Mine> ptr) {
    mines.emplace_back(ptr);
}

void Player::newTurn() {
    for(auto &it: heroes)
    {
        it->resetMove();
    }
}

const std::string &Player::getName() const {
    return name;
}
