//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_MAINMENU_H
#define HIROLSY_MAINMENU_H


#include "../StateMachine.h"
class MainMenu: public State {
public:

    MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
             StateMachine &stateMachine);

};


#endif //HIROLSY_MAINMENU_H
