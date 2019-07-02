//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GAME_H
#define HIROLSY_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "GUI/StateMachine.h"
#include "GameLogic/Player.h"
#include "GameLogic/Map.h"
//class StateMachine;
class Game {
    StateMachine stateMachine;
    sf::RenderWindow window;
    std::unique_ptr<Map> map = std::make_unique<Map>(Map::load(stateMachine));
public:
    const Map & getMap() const;
    Game();
    Game(unsigned int width, unsigned int height);

};


#endif //HIROLSY_GAME_H
