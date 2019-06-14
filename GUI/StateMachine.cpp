//
// Created by adao1003 on 5/12/19.
//

#include "StateMachine.h"
#include "GameStates/MainMenuState.h"


StateMachine::StateMachine(sf::RenderWindow &window, EventQueue &queue)
        : window(window), currentState(std::dynamic_pointer_cast<State>(std::make_shared<MainMenuState>(window, queue, (*this), nullptr))), eventQueue(queue) {}

void StateMachine::render() {
    currentState->render();
}

void StateMachine::input() {
    currentState->input();
}

void StateMachine::pullState() {
    currentState=currentState->getPrevState();
}

void StateMachine::pushState(const std::shared_ptr<State>& state) {
    currentState=state;
}

std::shared_ptr<State> StateMachine::createState(stateName name) {
    switch (name) {
        case MainMenu:
            return std::dynamic_pointer_cast<State>(std::make_shared<MainMenuState>(window, eventQueue, this));
            break;
    }
}

