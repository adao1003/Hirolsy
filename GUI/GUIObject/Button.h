//
// Created by adao1003 on 5/20/19.
//

#ifndef HIROLSY_BUTTON_H
#define HIROLSY_BUTTON_H


#include <SFML/Graphics/Texture.hpp>
#include "GUIObject.h"

class Button: public GUIObject {
    sf::Sprite sprite;
public:

    Button(sf::RenderWindow &window, sf::Texture &texture, const sf::Vector2f &vec,
           const std::function<void(GUIObject&, StateMachine &)> &onClick= GUIObject::empty);

    void draw() override;

    bool isMouseHover() override;
};


#endif //HIROLSY_BUTTON_H