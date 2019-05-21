//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_GUIOBJECT_H
#define HIROLSY_GUIOBJECT_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include "../StateMachine.h"

class StateMachine;
class GUIObject {
protected:
    std::function<void(StateMachine&)> onClick;
    sf::Sprite sprite;
public:
};


#endif //HIROLSY_GUIOBJECT_H
