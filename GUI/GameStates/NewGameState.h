//
// Created by adao1003 on 6/12/19.
//

#ifndef HIROLSY_NEWGAMESTATE_H
#define HIROLSY_NEWGAMESTATE_H


#include "../StateMachine.h"

class NewGameState: public State {
public:
    NewGameState(sf::RenderWindow &window, StateMachine &stateMachine,
                 const std::shared_ptr<State> &prevState);
};


#endif //HIROLSY_NEWGAMESTATE_H
