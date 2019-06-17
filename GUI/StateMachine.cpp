//
// Created by adao1003 on 5/12/19.
//

#include "StateMachine.h"
#include "GameStates/MainMenuState.h"
#include "StateFactory.h"


StateMachine::StateMachine(sf::RenderWindow &window, EventQueue &queue, Game &game)
        : window(window), eventQueue(queue),
          stateFactory(window, *this, eventQueue), game(game) {
    currentState= stateFactory.createState(StateFactory::stateName::MainMenu);
}

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
    state->setPrevState(currentState);
    currentState=state;
}

