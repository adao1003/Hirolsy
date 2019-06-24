//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAINGAMESTATE_H
#define HIROLSY_MAINGAMESTATE_H


#include "../StateMachine.h"
#include "../../Game.h"
class Map;
class MainGameState: public State{
    Map& map = const_cast<Map&>(stateMachine.getGame().getMap());
public:
    MainGameState(sf::RenderWindow &window, StateMachine &stateMachine, const std::shared_ptr<State> &prevState);
};


#endif //HIROLSY_MAINGAMESTATE_H
