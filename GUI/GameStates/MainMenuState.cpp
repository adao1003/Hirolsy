//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Event.hpp>
#include "MainMenuState.h"
#include "../GUIObject/Button.h"
#include "../ResourcesContainer.h"
#include "State.h"
#include "NewGameState.h"

MainMenuState::MainMenuState(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
                   const std::shared_ptr<State> &prevState) : State(window, eventQueue, stateMachine, prevState)
                   {
    items.emplace_back(std::make_shared<Button>(window, ResourcesContainer::getInstance().getTexture("NewGame.png"), sf::Vector2f(100,100), NewGameButtonFun));
                   }

void MainMenuState::NewGameButtonFun(GUIObject& guiObject, StateMachine &stateM) {
    stateM.pushState(stateM.stateFactory.createState(StateFactory::stateName::NewGame));
}

