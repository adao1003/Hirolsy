//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATEMACHINE_H
#define HIROLSY_STATEMACHINE_H


#include "GameStates/State.h"
#include "GameStates/MainMenu.h"
#include "../Events/EventQueue.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class State;
class StateMachine {
    std::shared_ptr<State> currentState;
    sf::RenderWindow& window;
    EventQueue& eventQueue;
public:
    StateMachine(sf::RenderWindow &window, EventQueue &queue);
};


#endif //HIROLSY_STATEMACHINE_H
