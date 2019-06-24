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
    std::vector<std::shared_ptr<GameObject>> buildings;
    sf::Texture* fieldsTexture = &ResourcesContainer::getInstance().getTexture("fields.png");
    std::unique_ptr<sf::RenderTexture> tileMap = std::make_unique<sf::RenderTexture>();
    PlayerQueue playerQueue;
    void addBuilding(const std::shared_ptr<GameObject> &obj);
public:
    void generatorTileMap();
    const std::unique_ptr<sf::RenderTexture> &getTileMap() const;
    static Map load();

    const std::vector<std::shared_ptr<GameObject>> &getBuildings() const;
};


#endif //HIROLSY_MAP_H
