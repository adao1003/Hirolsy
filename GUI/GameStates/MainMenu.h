//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_MAINMENU_H
#define HIROLSY_MAINMENU_H


#include "State.h"

class MainMenu: public State {
public:
    MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue);

    void render() override;
    void input() override;
};


#endif //HIROLSY_MAINMENU_H
