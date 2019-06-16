//
// Created by adao1003 on 6/12/19.
//

#include "NewGameState.h"
#include <SFML/Window/Event.hpp>
#include "../GUIObject/Button.h"
#include "../ResourcesContainer.h"
#include "State.h"

NewGameState::NewGameState(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
                           const std::shared_ptr<State> &prevState) : State(window, eventQueue, stateMachine, prevState) {
    auto temp = std::make_shared<Button>(window, ResourcesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(50,100), [&](GUIObject& guiObject, StateMachine &stateM){stateM.pullState();});
    items.emplace_back(std::move(temp));
}
