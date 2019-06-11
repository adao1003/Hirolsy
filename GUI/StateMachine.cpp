//
// Created by adao1003 on 5/12/19.
//

#include "StateMachine.h"
#include "GameStates/MainMenu.h"


StateMachine::StateMachine(sf::RenderWindow &window, EventQueue &queue)
        : window(window), currentState(std::dynamic_pointer_cast<State>(std::make_shared<MainMenu>(nullptr, window, queue, *this))), eventQueue(queue) {}

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
