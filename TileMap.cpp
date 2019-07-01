//
// Created by adao1003 on 6/28/19.
//

#include "TileMap.h"
#include <SFML/Graphics/RenderTarget.hpp>
void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(array, states);
}

void TileMap::load(sf::Texture *tileset, sf::Vector2u tileSize,
                   const std::vector<std::vector<std::unique_ptr<Field>>> &fieldLayer){
    texture = tileset;
    array.setPrimitiveType(sf::Quads);
    array.resize(fieldLayer.size()*fieldLayer[0].size()*4);
    for(unsigned int i = 0; i<fieldLayer.size(); i++)
        for(unsigned int j = 0; j<fieldLayer[i].size();j++)
        {
            auto coord = fieldLayer[i][j]->getOffset();
            sf::Vertex* quad = &array[(i+j*fieldLayer.size())*4];
            quad[0].position = sf::Vector2f(i*64,j*64);
            quad[1].position = sf::Vector2f((i+1)*64,j*64);
            quad[2].position = sf::Vector2f((i+1)*64,(j+1)*64);
            quad[3].position = sf::Vector2f(i*64,(j+1)*64);

            quad[0].texCoords = sf::Vector2f(coord.x,coord.y);
            quad[1].texCoords = sf::Vector2f(coord.x+64,coord.y);
            quad[2].texCoords = sf::Vector2f(coord.x+64,coord.y+64);
            quad[3].texCoords = sf::Vector2f(coord.x, coord.y+64);
        }

}
