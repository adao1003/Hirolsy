//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Mouse.hpp>
#include "GUIObject.h"

void GUIObject::draw() {
    window.draw(sprite);
}

bool GUIObject::isMouseHover() {
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

GUIObject::GUIObject(sf::RenderWindow &window) : window(window) {}
