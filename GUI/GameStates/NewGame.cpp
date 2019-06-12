//
// Created by adao1003 on 6/12/19.
//

#include "NewGame.h"

NewGame::NewGame(const std::shared_ptr<State> &prevState, sf::RenderWindow &window, EventQueue &eventQueue,
                 StateMachine &stateMachine) : State(prevState, window, eventQueue, stateMachine) {

}
