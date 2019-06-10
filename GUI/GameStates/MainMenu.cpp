//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenu.h"

void MainMenu::render() {
    for(auto& it : items)
    {
        it->draw();
    }
}

void MainMenu::input() {
    bool isClicked = false;
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        }
    }

    for(auto& it:items)
    {
        if(it->isMouseHover())
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left));
                it->onClick(stateMachine);
        }
    }
}

MainMenu::MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
                   StateMachine &stateMachine) : State(prevState, window, eventQueue, stateMachine)
                   {}
