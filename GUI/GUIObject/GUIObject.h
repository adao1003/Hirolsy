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
void test (StateMachine& e);
class GUIObject {
protected:
    sf::Sprite sprite;
    sf::RenderWindow& window;
public:
    std::function<void(StateMachine&)> onClick = test;
    void draw();
    bool isMouseHover();
    void pullState();
    GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec);
};


#endif //HIROLSY_GUIOBJECT_H