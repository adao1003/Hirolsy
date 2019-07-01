#include <utility>

//
// Created by adao1003 on 5/12/19.
//

#include <SFML/Window/Mouse.hpp>
#include "GUIObject.h"

GUIObject::GUIObject(sf::RenderWindow &window, const sf::Vector2f &vec,
                     std::function<void(GUIObject &, StateMachine &)> onClick)
        : window(window), onClick(std::bind(onClick, std::ref(*this), std::placeholders::_1)) {}

void GUIObject::setOnRightClick(std::function<void(GUIObject &, StateMachine &)> p) {
    onRightClick = std::bind(p, std::ref(*this), std::placeholders::_1);
}

sf::RenderWindow &GUIObject::getWindow() const {
    return window;
}

