//
// Created by adao1003 on 6/19/19.
//

#include "MainGameState.h"
#include "../GUIObject/MapView.h"
#include "../../Game.h"

MainGameState::MainGameState(sf::RenderWindow &window, StateMachine &stateMachine,
                             const std::shared_ptr<State> &prevState) : State(window, stateMachine, prevState) {

    Map& d = const_cast<Map&>(stateMachine.getGame().getMap());
    items.emplace_back(std::make_shared<MapView>(window, sf::Vector2f(100,100), d));
}
