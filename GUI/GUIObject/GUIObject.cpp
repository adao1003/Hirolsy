#include <utility>

//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Mouse.hpp>
#include "GUIObject.h"

void GUIObject::draw() {
    window.draw(sprite);
}

bool GUIObject::isMouseHover() {
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

GUIObject::GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec,
                     std::function<void(GUIObject&, StateMachine &)> onClick) : window(window), sprite(sprite), onClick(std::bind(onClick, std::ref(*this), std::placeholders::_1)) {
    sprite.setPosition(vec);
}

void GUIObject::setOnRightClick(std::function<void(GUIObject &, StateMachine &)> p) {
    onRightClick = std::bind(p, std::ref(*this), std::placeholders::_1);
}

sf::RenderWindow &GUIObject::getWindow() const {
    return window;
}

