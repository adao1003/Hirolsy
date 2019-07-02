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
#include "Hero.h"
#include "../TileMap.h"
#include "../GUI/StateMachine.h"
#include "Battle/Battle.h"

class Map {
    std::vector<std::vector<std::unique_ptr<Field>>> fieldLayer;
    std::vector<std::shared_ptr<GameObject>> buildings;
    std::vector<std::shared_ptr<GameObject>> dynamicObjects;
    sf::Texture* fieldsTexture = &ResourcesContainer::getInstance().getTexture("fields.png");
    TileMap tileMap;
    PlayerQueue playerQueue;
    sf::Vector2i selection;
    std::shared_ptr<Hero> selectedHero;
    std::unique_ptr<Battle> currentBattle = nullptr;
    void addBuilding(const std::shared_ptr<GameObject> &obj);

public:
    Map(StateMachine &stateMachine);
    void addHero(const std::shared_ptr<Hero> &obj);
    void generatorTileMap();
    const TileMap & getTileMap() const;
    static Map load(StateMachine &stateMachine);
    const std::vector<std::shared_ptr<GameObject>> &getBuildings() const;
    const std::unique_ptr<Battle> &getCurrentBattle() const;
    void select(unsigned int x, unsigned int y);
    const std::vector<std::shared_ptr<GameObject>> &getDynamicObjects() const;
    const sf::Vector2i &getSelection() const;
    Player* currentPlayer() const;
    void moveHero();
    void newTurn();
    void removeHero(Hero* hero);
    StateMachine& stateMachine;
};


#endif //HIROLSY_MAP_H
