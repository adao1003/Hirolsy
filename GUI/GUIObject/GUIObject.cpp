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

GUIObject::GUIObject(sf::RenderWindow &window, sf::Sprite sprite, const sf::Vector2f &vec) : window(window), sprite(sprite)
{
    sprite.setPosition(vec.x, vec.y);
}

void GUIObject::pullState() {

}

void test (StateMachine& e)
{
std::cout << "test" << std::endl;
}