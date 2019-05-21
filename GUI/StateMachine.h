//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATEMACHINE_H
#define HIROLSY_STATEMACHINE_H


#include "GameStates/State.h"
#include <memory>
class State;
class StateMachine {
    std::shared_ptr<State> currentState;
};


#endif //HIROLSY_STATEMACHINE_H
