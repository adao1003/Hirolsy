//
// Created by adao1003 on 7/1/19.
//

#include <iostream>
#include "Battle.h"
#include "../Map.h"

Battle::Battle(Hero *attackerHero, Hero *attackedHero, Map *map)
        : AttackerHero(attackerHero), AttackedHero(attackedHero), map(map) {
    for(unsigned int i ; i<12;i++)
        battleField.emplace_back(12);
    for(unsigned int i = 0; i<12 ; i++)
        for(unsigned int j =0 ; j < 12; j++)
        {
            auto temp = battleField[i][j].getSprite();
            temp.setPosition(i*64, j*64);
            battleField[i][j].setSprite(temp);
        }
    for(auto &it:attackerHero->getUnits()){
        addAttackerUnit(it);
    }
    for(auto &it:attackedHero->getUnits()){
        addAttackedUnit(it);
    }
    for(unsigned int i = 0; i<12 ; i++)
        for(unsigned int j =0 ; j < 12; j++)
        {
            if(battleField[i][j].getUnit()) {
                battleField[i][j].getUnit()->setX(i);
                battleField[i][j].getUnit()->setY(j);
            }
        }
    currentPlayer = attackerHero->getOwner();
}

void Battle::addAttackerUnit(const std::shared_ptr<Unit> &unit) {
    static std::pair<unsigned int,unsigned int> coord = {2 ,10};
    battleField[coord.first][coord.second].addUnit(unit);
    AttackerUnits.push_back(unit);
    coord.first++;
}

void Battle::addAttackedUnit(const std::shared_ptr<Unit> &unit) {
    static std::pair<unsigned int,unsigned int> coord = {2,1};
    battleField[coord.first][coord.second].addUnit(unit);
    AttackedUnits.push_back(unit);
    coord.first++;
}

void Battle::select(unsigned int x, unsigned int y) {
    selection = {x,y};
    if(!currentUnit){
        if(AttackerHero->getOwner()==currentPlayer)
            if(std::count(AttackerUnits.begin(), AttackerUnits.end(), battleField[x][y].getUnit()))
                currentUnit=battleField[x][y].getUnit();
        if(AttackedHero->getOwner()==currentPlayer)
            if(std::count(AttackedUnits.begin(), AttackedUnits.end(), battleField[x][y].getUnit()))
                currentUnit=battleField[x][y].getUnit();
    }
    else
    {
        moveUnit();
    }
}

const sf::Vector2u &Battle::getSelection() const {
    return selection;
}

void Battle::changePlayer() {
    if (currentPlayer==AttackerHero->getOwner()) {
        currentPlayer = AttackedHero->getOwner();
        for(auto& it: AttackedHero->getUnits())
            it->resetMove();
    }
    else {
        currentPlayer = AttackerHero->getOwner();
        for(auto& it: AttackerHero->getUnits())
            it->resetMove();
    }
}

void Battle::moveUnit() {
  //  std::cout << "fff" << std::endl;
   // auto x= static_cast<int>(currentUnit->getX()-selection.x);
    //auto y= static_cast<int>(currentUnit->getY()-selection.y);
   // std::cout << x << " " << y << std::endl;
    //std::cout << currentUnit->getX() << " " << currentUnit->getY() << std::endl;
    if(abs(static_cast<int>(currentUnit->getX()-selection.x))<=1&&abs(static_cast<int>(currentUnit->getY()-selection.y))<=1) {
    //    std::cout << "df" << std::endl;
        if(!battleField[selection.x][selection.y].getUnit()) {
            if (currentUnit->move()) {
                battleField[currentUnit->getX()][currentUnit->getY()].removeUnit();
                currentUnit->setPoz(selection.x, selection.y);
                battleField[selection.x][selection.y].addUnit(currentUnit);

            }
        }
        else
        {
            if(battleField[selection.x][selection.y].getUnit()&&currentUnit->getCurrentMove()&&battleField[selection.x][selection.y].getUnit()->getOwner()!=currentPlayer)
            {
                currentUnit->attack(*battleField[selection.x][selection.y].getUnit());
                if(battleField[selection.x][selection.y].getUnit()->isDead()) {
                    removeUnit(battleField[selection.x][selection.y].getUnit());
                    if(AttackedUnits.empty()){
                        map->removeHero(AttackedHero);
                        map->stateMachine.pullState();
                        return;}
                    if(AttackerUnits.empty()){
                        map->removeHero(AttackerHero);
                        map->stateMachine.pullState();
                        return;}

                }
            }
        }
    }
    currentUnit = nullptr;
}

void Battle::removeUnit(std::shared_ptr<Unit> unit) {

    auto temp =  std::find(AttackedHero->getUnits().begin(), AttackedHero->getUnits().end(), unit);
    if(temp!=AttackedHero->getUnits().end())
        const_cast<std::vector<std::shared_ptr<Unit>>&>(AttackedHero->getUnits()).erase(temp);

    auto temp1 =  std::find(AttackerHero->getUnits().begin(), AttackerHero->getUnits().end(), unit);
    if(temp1!=AttackedHero->getUnits().end())
        const_cast<std::vector<std::shared_ptr<Unit>>&>(AttackerHero->getUnits()).erase(temp1);

    auto temp2 =  std::find(AttackerUnits.begin(), AttackerUnits.end(), unit);
    if(temp2!=AttackerUnits.end())
        const_cast<std::vector<std::shared_ptr<Unit>>&>(AttackerUnits).erase(temp2);

    auto temp3 =  std::find(AttackedUnits.begin(), AttackedUnits.end(), unit);
    if(temp3!=AttackedUnits.end())
        const_cast<std::vector<std::shared_ptr<Unit>>&>(AttackedUnits).erase(temp3);
    battleField[unit->getX()][unit->getY()].removeUnit();
}

void Battle::setMap(Map *map) {
    Battle::map = map;
}
