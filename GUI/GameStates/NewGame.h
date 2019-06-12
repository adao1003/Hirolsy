//
// Created by adao1003 on 6/12/19.
//

#ifndef HIROLSY_NEWGAME_H
#define HIROLSY_NEWGAME_H


#include "../StateMachine.h"

class NewGame: public State {
public:
    NewGame(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
            StateMachine &stateMachine);
};


#endif //HIROLSY_NEWGAME_H
