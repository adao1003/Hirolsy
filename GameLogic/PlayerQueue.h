//
// Created by adao1003 on 6/23/19.
//

#ifndef HIROLSY_PLAYERQUEUE_H
#define HIROLSY_PLAYERQUEUE_H


#include <vector>
#include "Player.h"

class PlayerQueue {
    std::vector<std::shared_ptr<Player>> queue;
    std::vector<std::shared_ptr<Player>>::iterator currentPlayer;
public:
    void nextPlayer();
    void addPlayer(const std::shared_ptr<Player> &player);
    const std::shared_ptr<Player> &getCurrentPlayer() const;
};


#endif //HIROLSY_PLAYERQUEUE_H
