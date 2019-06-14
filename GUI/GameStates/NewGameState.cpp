//
// Created by adao1003 on 6/12/19.
//

#include "NewGameState.h"
#include <SFML/Window/Event.hpp>
#include "../GUIObject/Button.h"
#include "../TexturesContainer.h"
#include "State.h"

NewGameState::NewGameState(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
                           const std::shared_ptr<State> &prevState = nullptr) : State(window, eventQueue, stateMachine, prevState) {
    auto temp = std::make_shared<Button>(window, TexturesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(100,100), GUIObject::test);
    items.emplace_back(std::move(temp));
}
