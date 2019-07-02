//
// Created by adao1003 on 7/1/19.
//

#include "BattleState.h"
#include "../GUIObject/BattleView.h"
#include "../GUIObject/Button.h"
#include "../../GameLogic/Battle/Battle.h"

BattleState::BattleState(sf::RenderWindow &window, StateMachine &stateMachine, const std::shared_ptr<State> &prevState)
        : State(window, stateMachine, prevState) {
    Map& d = const_cast<Map&>(stateMachine.getGame().getMap());
    items.emplace_back(std::make_shared<BattleView>(window, sf::Vector2f(100,100), d));
    items.emplace_back(std::make_shared<Button>(window, ResourcesContainer::getInstance().getTexture("NewTurn.png"), sf::Vector2f(1500,100), NewTurnButtonFun));

}

void BattleState::NewTurnButtonFun(GUIObject &guiObject, StateMachine &stateM) {
    const_cast<Map&>(stateM.getGame().getMap()).getCurrentBattle()->changePlayer();
}
