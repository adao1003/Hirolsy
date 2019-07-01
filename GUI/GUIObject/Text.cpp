//
// Created by adao1003 on 7/1/19.
//

#include "Text.h"

void Text::draw() {
    window.draw(text);
}

bool Text::isMouseHover() {
    return false;
}

Text::Text(sf::RenderWindow &window, const sf::Vector2f &vec, const sf::String &string, const sf::Font &font)
        : GUIObject(window, vec), text(string, font) {
    text.setPosition(vec);
}

void Text::setText(const sf::String& string) {
    text.setString(string);
}
