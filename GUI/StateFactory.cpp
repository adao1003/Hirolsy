//
// Created by adao1003 on 6/16/19.
//

#include "GameStates/MainMenuState.h"
#include "StateMachine.h"
#include "StateFactory.h"
#include "GameStates/NewGameState.h"

std::shared_ptr<State> StateFactory::createState(stateName name, std::shared_ptr<State> prevState) {
    switch (name) {
        case MainMenu:
            return std::dynamic_pointer_cast<State>(std::make_shared<MainMenuState>(window, stateMachine, prevState));
            break;
        case NewGame:
            return std::dynamic_pointer_cast<State>(std::make_shared<NewGameState>(window, stateMachine, prevState));
            break;
    }
}

StateFactory::StateFactory(sf::RenderWindow &window, StateMachine &stateMachine) : window(window),
                                                                                                     stateMachine(
                                                                                                             stateMachine){}
