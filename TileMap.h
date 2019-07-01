//
// Created by adao1003 on 6/28/19.
//

#ifndef HIROLSY_TILEMAP_H
#define HIROLSY_TILEMAP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "GameLogic/Fields/Field.h"

class TileMap: public sf::Drawable, public sf::Transformable {
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::VertexArray array;
    sf::Texture* texture;

public:
    void load(sf::Texture* tileset, sf::Vector2u tileSize, const std::vector<std::vector<std::unique_ptr<Field>>>& fieldLayer);
};


#endif //HIROLSY_TILEMAP_H