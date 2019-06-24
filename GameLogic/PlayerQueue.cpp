//
// Created by adao1003 on 6/23/19.
//

#include "PlayerQueue.h"

void PlayerQueue::nextPlayer() {
    if(++currentPlayer==queue.end())
        currentPlayer=queue.begin();
}

const std::shared_ptr<Player> &PlayerQueue::getCurrentPlayer() const {
    return *currentPlayer;
}

void PlayerQueue::addPlayer(const std::shared_ptr<Player> &player) {
    queue.push_back(player);
        currentPlayer = queue.begin();
}
