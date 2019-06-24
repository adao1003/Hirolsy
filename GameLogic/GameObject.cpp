//
// Created by adao1003 on 6/17/19.
//

#include "GameObject.h"

GameObject::GameObject(unsigned int x, unsigned int y) : x(x), y(y) {}

GameObject::GameObject() {}

GameObject::GameObject(unsigned int x, unsigned int y, const sf::Texture &texture) : sprite(texture), x(x), y(y) {
    sprite.setPosition(x*64, y*64);
}

unsigned int GameObject::getX() const {
    return x;
}

unsigned int GameObject::getY() const {
    return y;
}

const sf::Sprite &GameObject::getSprite() const {
    return sprite;
}
