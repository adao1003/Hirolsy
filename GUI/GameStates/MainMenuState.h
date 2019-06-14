//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_MAINMENUSTATE_H
#define HIROLSY_MAINMENUSTATE_H


#include "../StateMachine.h"
class MainMenuState: public State {
public:

    MainMenuState(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
             const std::shared_ptr<State> &prevState);

};


#endif //HIROLSY_MAINMENUSTATE_H
