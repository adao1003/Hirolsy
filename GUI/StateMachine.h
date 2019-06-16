//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATEMACHINE_H
#define HIROLSY_STATEMACHINE_H


#include "GameStates/State.h"
#include "GameStates/MainMenuState.h"
#include "../Events/EventQueue.h"
#include "StateFactory.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class State;
class StateMachine {
    std::shared_ptr<State> currentState;
    EventQueue& eventQueue;
    sf::RenderWindow& window;
public:
    StateMachine(sf::RenderWindow &window, EventQueue &queue);
    void render();
    void input();
    void pullState();
    void pushState(const std::shared_ptr<State>& state);
    StateFactory stateFactory;

};


#endif //HIROLSY_STATEMACHINE_H
