//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GAME_H
#define HIROLSY_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "GUI/StateMachine.h"

class Game {
    StateMachine stateMachine;
    sf::RenderWindow window;
};


#endif //HIROLSY_GAME_H
