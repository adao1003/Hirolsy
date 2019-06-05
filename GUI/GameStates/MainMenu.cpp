//
// Created by adao1003 on 5/12/19.
//

#include "MainMenu.h"

void MainMenu::render() {
    for(auto& it : items)
    {
        it->draw();
    }
}

void MainMenu::input() {
    for(auto& it:items)
    {
        if(it->isMouseHover())
        {

        }
    }
}

MainMenu::MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue) : State(
        prevState, window, eventQueue) {}
