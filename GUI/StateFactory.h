//
// Created by adao1003 on 6/16/19.
//

#ifndef HIROLSY_STATEFACTORY_H
#define HIROLSY_STATEFACTORY_H


#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameStates/State.h"
#include "GameStates/MainMenuState.h"
#include "../Events/EventQueue.h"

class StateFactory {
    sf::RenderWindow& window;
    StateMachine& stateMachine;
public:
    StateFactory(sf::RenderWindow &window, StateMachine &stateMachine);
    enum stateName{
        MainMenu,
        NewGame,
        MainGame
    };
    std::shared_ptr<State> createState(stateName name, std::shared_ptr<State> prevState = nullptr);
};


#endif //HIROLSY_STATEFACTORY_H
