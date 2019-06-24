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
    static void empty(GUIObject& g, StateMachine& s) {}

public:
    //static void test (StateMachine& e);
    std::function<void(StateMachine&)> onClick ;
    std::function<void(StateMachine&)> onRightClick = std::bind(GUIObject::empty, std::ref(*this), std::placeholders::_1);
    virtual void draw();
    bool isMouseHover();
    virtual void update() {};
    GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec,
              std::function<void(GUIObject&, StateMachine &)> onClick = GUIObject::empty);
    void setOnRightClick(std::function<void(GUIObject &, StateMachine &)> p);
};


#endif //HIROLSY_GUIOBJECT_H