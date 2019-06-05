//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GAME_H
#define HIROLSY_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "GUI/StateMachine.h"
#include "Events/EventQueue.h"

class Game {
    StateMachine stateMachine;
    sf::RenderWindow window;
    EventQueue eventQueue;
public:
    Game() : stateMachine(window, eventQueue) {}
};


#endif //HIROLSY_GAME_H
