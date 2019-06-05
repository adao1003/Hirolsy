//
// Created by adao1003 on 5/12/19.
//

#include "StateMachine.h"
#include "GameStates/MainMenu.h"


StateMachine::StateMachine(sf::RenderWindow &window, EventQueue &queue)
        : window(window), currentState(std::dynamic_pointer_cast<State>(std::make_shared<MainMenu>(nullptr, window, queue))), eventQueue(queue) {}
