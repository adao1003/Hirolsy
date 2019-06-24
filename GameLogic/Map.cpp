//
// Created by adao1003 on 5/13/19.
//

#include <SFML/Graphics/Sprite.hpp>
#include "Map.h"
#include "Fields/Grass.h"
#include "Fields/Mountains.h"
#include "Fields/Road.h"
#include "Mines/Quarry.h"

void Map::generatorTileMap() {
    tileMap->create(fieldLayer[0].size()*64, fieldLayer.size()*64);
    for (int i = 0; i < fieldLayer.size(); ++i) {
        for (int j = 0; j < fieldLayer[0].size(); ++j) {
            auto temp = sf::Sprite(*fieldsTexture, sf::IntRect(fieldLayer[i][j]->getOffset(), sf::Vector2i(64,64)));
            temp.setPosition(i*64, j*64);
            tileMap->draw(temp);
        }
    }
    tileMap->display();
}

Map Map::load() {
    Map map;
    for(int i = 0;i<100;i++)
        map.fieldLayer.emplace_back(100);
    for (int i = 0; i < 100; ++i) {
        for(int j = 0; j< 100; j++)
            map.fieldLayer[i][j]=std::make_unique<Grass>();
    }
    map.fieldLayer[0][0] =std::make_unique<Mountains>();
    map.fieldLayer[0][1] =std::make_unique<Mountains>();
    map.fieldLayer[0][2] =std::make_unique<Mountains>();
    map.fieldLayer[0][3] =std::make_unique<Mountains>();
    map.fieldLayer[4][4] =std::make_unique<Road>();
    map.fieldLayer[4][5] =std::make_unique<Road>();
    map.fieldLayer[4][6] =std::make_unique<Road>();
    map.fieldLayer[4][7] =std::make_unique<Road>();
    map.addBuilding(std::make_shared<Quarry>(5,5));
    return map;
}

const std::unique_ptr<sf::RenderTexture> &Map::getTileMap() const {
    return tileMap;
}

void Map::addBuilding(const std::shared_ptr<GameObject> &obj) {
    fieldLayer[obj->getX()][obj->getY()]->addBuilding(obj);
    buildings.push_back(obj);
}

const std::vector<std::shared_ptr<GameObject>> &Map::getBuildings() const {
    return buildings;
}
