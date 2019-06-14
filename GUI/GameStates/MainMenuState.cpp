//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenuState.h"
#include "../GUIObject/Button.h"
#include "../TexturesContainer.h"
#include "State.h"
#include "NewGameState.h"

MainMenuState::MainMenuState(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
                   const std::shared_ptr<State> &prevState) : State(window, eventQueue, stateMachine, prevState)
                   {
    auto temp = std::make_shared<Button>(window, TexturesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(100,100));
    items.emplace_back(std::move(temp));
                   }

