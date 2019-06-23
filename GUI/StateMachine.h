//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATEMACHINE_H
#define HIROLSY_STATEMACHINE_H


#include "GameStates/State.h"
#include "GameStates/MainMenuState.h"
#include "StateFactory.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class State;
class Game;
class StateMachine {
    std::shared_ptr<State> currentState;
    sf::RenderWindow& window;
    Game& game;
public:
    StateMachine(sf::RenderWindow &window, Game &game);
    Game &getGame() const;
    void render();
    void input();
    void pullState();
    void pushState(const std::shared_ptr<State>& state);
    StateFactory stateFactory;
};


#endif //HIROLSY_STATEMACHINE_H
