//
// Created by adao1003 on 5/12/19.
//

#include "Game.h"

Game::Game(unsigned int width, unsigned int height) : window(sf::VideoMode(height, width ), "Hirolsy"), stateMachine(window, eventQueue) {
    window.setFramerateLimit(60);
    for(;;)
    {
        window.clear(sf::Color::Black);
        stateMachine.render();
        window.display();
        stateMachine.input();
    }
}
