//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GUIOBJECT_H
#define HIROLSY_GUIOBJECT_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include "../StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class StateMachine;

class GUIObject {
protected:
    sf::Sprite sprite;
    sf::RenderWindow& window;
public:
    static void test (StateMachine& e);
    std::function<void(StateMachine&)> onClick = test;
    void draw();
    bool isMouseHover();
    GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec);
    GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec,
              std::function<void(StateMachine &)> onClick);
};


#endif //HIROLSY_GUIOBJECT_H