//
// Created by adao1003 on 6/19/19.
//

#include "MainGameState.h"
#include "../GUIObject/MapView.h"
#include "../../Game.h"
#include "../GUIObject/Button.h"
#include "../GUIObject/Text.h"

MainGameState::MainGameState(sf::RenderWindow &window, StateMachine &stateMachine,
                             const std::shared_ptr<State> &prevState) : State(window, stateMachine, prevState) {

    Map& d = const_cast<Map&>(stateMachine.getGame().getMap());
    items.emplace_back(std::make_shared<MapView>(window, sf::Vector2f(100,100), d));
    items.emplace_back(std::make_shared<Button>(window, ResourcesContainer::getInstance().getTexture("NewTurn.png"), sf::Vector2f(1500,100), NewTurnButtonFun));
    text0 = std::make_shared<Text>(window, sf::Vector2f(50,50), "grgtregdgred");
    items.emplace_back(text0);
}

void MainGameState::NewTurnButtonFun(GUIObject &guiObject, StateMachine &stateM) {
    const_cast<Map&>(stateM.getGame().getMap()).newTurn();
}

void MainGameState::render() {
    auto temp = stateMachine.getGame().getMap().currentPlayer()->getName();
    text0->setText(temp);
    State::render();
}
