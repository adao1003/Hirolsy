//
// Created by adao1003 on 5/13/19.
//

#include <SFML/Graphics/Sprite.hpp>
#include "Map.h"
#include "Fields/Grass.h"
#include "Fields/Mountains.h"
#include "Fields/Road.h"
#include "Mines/Quarry.h"
#include "Units/Unit0.h"
#include "Units/Unit1.h"

void Map::generatorTileMap() {
    tileMap.load(fieldsTexture, sf::Vector2u(64,64), fieldLayer);
}

Map Map::load(StateMachine &stateMachine) {
    Map map(stateMachine);
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
    auto player0 = std::make_shared<Player>("Player0");
    auto player1 = std::make_shared<Player>("Player1");
    map.playerQueue.addPlayer(player0);
    map.playerQueue.addPlayer(player1);
    auto hero00 = std::make_shared<Hero>(6, 6, player0.get());
    auto hero10 = std::make_shared<Hero>(8, 8, player1.get());
    hero00->addUnit(std::make_shared<Unit0>(player0.get()));
//    hero00->addUnit(std::make_shared<Unit1>(player0.get()));
//    hero00->addUnit(std::make_shared<Unit1>(player0.get()));
//    hero00->addUnit(std::make_shared<Unit0>(player0.get()));

    hero10->addUnit(std::make_shared<Unit0>(player1.get()));
//    hero10->addUnit(std::make_shared<Unit1>(player1.get()));
//    hero10->addUnit(std::make_shared<Unit0>(player1.get()));
//    hero10->addUnit(std::make_shared<Unit1>(player1.get()));
    map.addHero(hero00);
    map.addHero(hero10);
    return map;
}

const TileMap & Map::getTileMap() const {
    return tileMap;
}

void Map::addBuilding(const std::shared_ptr<GameObject> &obj) {
    fieldLayer[obj->getX()][obj->getY()]->addBuilding(obj);
    buildings.push_back(obj);
}

const std::vector<std::shared_ptr<GameObject>> &Map::getBuildings() const {
    return buildings;
}

void Map::select(unsigned int x, unsigned int y) {
    selection = sf::Vector2i(x,y);
    auto t = currentPlayer();
    if(selectedHero)
        moveHero();
    if(fieldLayer[x][y]->getVisitedObject())
        if(auto temp = std::dynamic_pointer_cast<Hero>((*fieldLayer[x][y]->getVisitedObject())))
            if(temp->getOwner()==currentPlayer())
                selectedHero=temp;
}

void Map::addHero(const std::shared_ptr<Hero> &obj) {
    fieldLayer[obj->getX()][obj->getY()]->addBuilding(obj);
    dynamicObjects.push_back(obj);
    obj->getOwner()->addHero(obj);
}

const std::vector<std::shared_ptr<GameObject>> &Map::getDynamicObjects() const {
    return dynamicObjects;
}

const sf::Vector2i &Map::getSelection() const {
    return selection;
}

Player *Map::currentPlayer() const {
    return playerQueue.getCurrentPlayer().get();
}

void Map::moveHero() {
    auto x= static_cast<int>(selectedHero->getX()-selection.x);
    auto y= static_cast<int>(selectedHero->getY()-selection.y);
    if(abs(static_cast<int>(selectedHero->getX()-selection.x))<=1&&abs(static_cast<int>(selectedHero->getY()-selection.y))<=1) {
        if(fieldLayer[selection.x][selection.y]->getVisitedObject())
            if(auto temp = std::dynamic_pointer_cast<Hero>((*fieldLayer[selection.x][selection.y]->getVisitedObject())))
                if(temp->getOwner()!=currentPlayer()){
                    currentBattle=std::make_unique<Battle>(selectedHero.get(), temp.get());
                    currentBattle->setMap(this);
                    stateMachine.pushState(stateMachine.stateFactory.createState(stateMachine.stateFactory.Battle));

                    return;
                }
        if(selectedHero->move(*fieldLayer[selection.x][selection.y].get()))
        {
            fieldLayer[selectedHero->getX()][selectedHero->getY()]->resetCost();
            selectedHero->setX(selection.x);
            selectedHero->setY(selection.y);
            fieldLayer[selection.x][selection.y]->addBuilding(selectedHero);
        }
    }
    selectedHero= nullptr;
}

void Map::newTurn() {
    playerQueue.nextPlayer();
}

Map::Map(StateMachine &stateMachine) : stateMachine(stateMachine) {}

const std::unique_ptr<Battle> &Map::getCurrentBattle() const {
    return currentBattle;
}

void Map::removeHero(Hero *hero) {
    for(auto it = dynamicObjects.begin(); it!=dynamicObjects.end();it++)
    {
        if(it->get()==hero){
            fieldLayer[hero->getX()][hero->getY()]->resetCost();
            dynamicObjects.erase(it);
            break;
        }

    }
}
