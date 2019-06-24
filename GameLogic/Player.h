//
// Created by adao1003 on 6/18/19.
//

#ifndef HIROLSY_PLAYER_H
#define HIROLSY_PLAYER_H


#include <memory>
#include "Town.h"
#include "Mines/Mine.h"
class Hero;
class Player {
    std::string name;
    std::vector<std::shared_ptr<Town>> town;
    std::vector<std::shared_ptr<Hero>> heroes;
    std::vector<std::shared_ptr<Mine>> mines;
public:
    Player(const std::string &name);
    void addTown(std::shared_ptr<Town> ptr);
    void addHero(std::shared_ptr<Hero> ptr);
    void addMine(std::shared_ptr<Mine> ptr);
    void newTurn();
};


#endif //HIROLSY_PLAYER_H
