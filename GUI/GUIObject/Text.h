//
// Created by adao1003 on 7/1/19.
//

#ifndef HIROLSY_TEXT_H
#define HIROLSY_TEXT_H


#include <SFML/Graphics/Text.hpp>
#include "GUIObject.h"
#include "../ResourcesContainer.h"

class Text: public GUIObject {
    sf::Text text;
public:
    void draw() override;

    Text(sf::RenderWindow &window, const sf::Vector2f &vec, const sf::String &string, const sf::Font &font = ResourcesContainer::getInstance().getFont("Arial.ttf"));
    bool isMouseHover() override;
    void setText(const sf::String& string);
};


#endif //HIROLSY_TEXT_H
