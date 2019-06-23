//
// Created by adao1003 on 6/18/19.
//

#ifndef HIROLSY_PLAYER_H
#define HIROLSY_PLAYER_H


#include <memory>
#include "Town.h"
#include "Hero.h"
#include "Mines/Mine.h"

class Player {
    std::string name;
    std::vector<std::shared_ptr<Town>> town;
    std::vector<std::shared_ptr<Hero>> heroes;
    std::vector<std::shared_ptr<Mine>> mines;
};


#endif //HIROLSY_PLAYER_H
