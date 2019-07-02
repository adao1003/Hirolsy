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
    sf::RenderWindow& window;
    static void empty(GUIObject& g, StateMachine& s) {}
public:
    //static void test (StateMachine& e);
    std::function<void(StateMachine&)> onClick;
    std::function<void(StateMachine&)> onRightClick = std::bind(GUIObject::empty, std::ref(*this), std::placeholders::_1);
    virtual void draw() {};
    virtual bool isMouseHover() {};
    virtual void update() {};
    GUIObject(sf::RenderWindow &window, const sf::Vector2f &vec,
              std::function<void(GUIObject &, StateMachine &)> onClick = GUIObject::empty);
    void setOnRightClick(std::function<void(GUIObject &, StateMachine &)> p);

    sf::RenderWindow &getWindow() const;
};


#endif //HIROLSY_GUIOBJECT_H