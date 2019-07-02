//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_FIELD_H
#define HIROLSY_FIELD_H


#include <variant>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "../GameObject.h"
#include <optional>

class Field {
protected:
    std::variant<double, std::shared_ptr<GameObject>> cost;
    sf::Vector2i offset;
public:
    Field(double cost, const sf::Vector2i &offset);
    double getCost();
    const sf::Vector2i &getOffset() const;
    virtual void resetCost() = 0;
    void addBuilding(const std::shared_ptr<GameObject>& ptr);
    std::optional<std::shared_ptr<GameObject>> getVisitedObject();
    virtual Field* clone() = 0;
};


#endif //HIROLSY_FIELD_H
