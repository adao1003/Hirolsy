//
// Created by adao1003 on 5/20/19.
//

#include <SFML/Window/Mouse.hpp>
#include "Button.h"

Button::Button(sf::RenderWindow &window, sf::Texture &texture, const sf::Vector2f &vec,
               const std::function<void(GUIObject&, StateMachine &)> &onClick) : GUIObject(window, vec, onClick), sprite(texture)
               {
    sprite.setPosition(vec);
               }

void Button::draw() {
    window.draw(sprite);
}

bool Button::isMouseHover() {
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

