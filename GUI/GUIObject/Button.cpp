//
// Created by adao1003 on 5/20/19.
//

#include "Button.h"

Button::Button(sf::RenderWindow &window, sf::Texture &texture, const sf::Vector2f &vec) : GUIObject(window,
                                                                                                    sf::Sprite(texture),
                                                                                                    vec) {
    sprite.setPosition(vec.x, vec.y);
}

Button::Button(sf::RenderWindow &window, sf::Texture &texture, const sf::Vector2f &vec,
               const std::function<void(StateMachine &)> &onClick) : GUIObject(window, sf::Sprite(texture), vec, onClick)
               {
    sprite.setPosition(vec.x, vec.y);
               }

