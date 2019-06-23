//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_FIELD_H
#define HIROLSY_FIELD_H


#include <variant>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "../GameObject.h"

class Field: public GameObject {
    std::variant<double, std::shared_ptr<GameObject>> cost;
    sf::Vector2i offset;
public:
    Field(double cost, const sf::Vector2i &offset);

    const sf::Vector2i &getOffset() const;
};


#endif //HIROLSY_FIELD_H
