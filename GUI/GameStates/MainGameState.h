//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAINGAMESTATE_H
#define HIROLSY_MAINGAMESTATE_H


#include "../StateMachine.h"
#include "../../Game.h"
#include "../GUIObject/Text.h"

class Map;
class MainGameState: public State{
    Map& map = const_cast<Map&>(stateMachine.getGame().getMap());
    static void NewTurnButtonFun(GUIObject &guiObject, StateMachine &stateM);
    std::shared_ptr<Text> text0;
public:
    MainGameState(sf::RenderWindow &window, StateMachine &stateMachine, const std::shared_ptr<State> &prevState);

    void render() override;
};


#endif //HIROLSY_MAINGAMESTATE_H
