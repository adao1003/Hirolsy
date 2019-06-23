//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAINGAMESTATE_H
#define HIROLSY_MAINGAMESTATE_H


#include "../StateMachine.h"

class MainGameState: public State{
public:
    MainGameState(sf::RenderWindow &window, StateMachine &stateMachine, const std::shared_ptr<State> &prevState);
};


#endif //HIROLSY_MAINGAMESTATE_H
