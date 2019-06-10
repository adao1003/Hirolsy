//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GUIOBJECT_H
#define HIROLSY_GUIOBJECT_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include "../StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>

class StateMachine;
class GUIObject {
protected:
    sf::Sprite sprite;
    sf::RenderWindow& window;
public:
    std::function<void(StateMachine&)> onClick;
    void draw();
    bool isMouseHover();

    GUIObject(sf::RenderWindow &window);
};


#endif //HIROLSY_GUIOBJECT_H