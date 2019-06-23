//
// Created by adao1003 on 5/13/19.
//

#ifndef HIROLSY_MAP_H
#define HIROLSY_MAP_H


#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include "GameObject.h"
#include "Fields/Field.h"
#include "../GUI/ResourcesContainer.h"
#include "PlayerQueue.h"

class MockMapLoader;
class Map {
    std::vector<std::vector<std::unique_ptr<Field>>> fieldLayer;
    sf::Texture* fieldsTexture = &ResourcesContainer::getInstance().getTexture("fields.png");
    std::unique_ptr<sf::RenderTexture> tileMap = std::make_unique<sf::RenderTexture>();
    PlayerQueue playerQueue;
public:
    void generatorTileMap();

    const std::unique_ptr<sf::RenderTexture> &getTileMap() const;

    static Map load();
};


#endif //HIROLSY_MAP_H
