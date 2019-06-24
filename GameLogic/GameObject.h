//
// Created by adao1003 on 6/17/19.
//

#ifndef HIROLSY_GAMEOBJECT_H
#define HIROLSY_GAMEOBJECT_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class GameObject {
    sf::Sprite sprite;
public:
    const sf::Sprite &getSprite() const;

private:
    unsigned int x = 0;
    unsigned int y = 0;
public:
    GameObject();
    GameObject(unsigned int x, unsigned int y);
    GameObject(unsigned int x, unsigned int y, const sf::Texture &texture);
    virtual void temp() {}; // Dla polimorfizmu ;)
    unsigned int getX() const;
    unsigned int getY() const;

    void setX(unsigned int x);

    void setY(unsigned int y);
};


#endif //HIROLSY_GAMEOBJECT_H
