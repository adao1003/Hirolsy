//
// Created by adao1003 on 7/1/19.
//

#ifndef HIROLSY_BATTLESTATE_H
#define HIROLSY_BATTLESTATE_H


#include "../StateMachine.h"
#include "../../GameLogic/Map.h"
#include "../../Game.h"

class BattleState: public State {
    Map& map = const_cast<Map&>(stateMachine.getGame().getMap());
    Battle& battle = const_cast<Battle&>(*(stateMachine.getGame().getMap().getCurrentBattle()));
    static void NewTurnButtonFun(GUIObject &guiObject, StateMachine &stateM);
public:
    BattleState(sf::RenderWindow &window, StateMachine &stateMachine, const std::shared_ptr<State> &prevState);
};


#endif //HIROLSY_BATTLESTATE_H
