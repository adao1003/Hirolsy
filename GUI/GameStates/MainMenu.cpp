//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenu.h"
#include "../GUIObject/Button.h"
#include "../TexturesContainer.h"
#include "State.h"

MainMenu::MainMenu(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
                   StateMachine &stateMachine) : State(prevState, window, eventQueue, stateMachine)
                   {
    auto temp = std::make_shared<Button>(window, TexturesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(100,100), GUIObject::test);
    items.emplace_back(std::move(temp));
                   }
