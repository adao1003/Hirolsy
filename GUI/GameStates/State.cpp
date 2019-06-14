//
// Created by adao1003 on 6/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenuState.h"
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
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                for(auto& it:items)
                {
                    if(it->isMouseHover())
                        if(event.mouseButton.button==sf::Mouse::Left)
                            it->onClick(stateMachine);
                }
                break;

        }
    }
//    for(auto& it:items)
//    {
//        if(it->isMouseHover())
//        {
//            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//                it->onClick(stateMachine);
//        }
//    }
}

void State::setPrevState(const std::shared_ptr<State> &prevState) {
    State::prevState = prevState;
}

const std::shared_ptr<State> &State::getPrevState() const {
    return prevState;
}
