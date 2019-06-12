//
// Created by adao1003 on 6/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenu.h"
#include "../GUIObject/Button.h"
#include "../TexturesContainer.h"
#include "State.h"

void State::render() {
    for(auto& it : State::items)
    {
        it->draw();
    }
}

void State::input() {
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
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                it->onClick(stateMachine);
        }
    }
}