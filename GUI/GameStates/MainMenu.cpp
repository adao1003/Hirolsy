//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenu.h"
#include "../GUIObject/Button.h"
#include "../TexturesContainer.h"

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
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                it->onClick(stateMachine);
        }
    }
}

MainMenu::MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
                   StateMachine &stateMachine) : State(prevState, window, eventQueue, stateMachine)
                   {
    auto temp = std::make_shared<Button>(window, TexturesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(100,100));
    items.emplace_back(std::move(temp));
                   }
