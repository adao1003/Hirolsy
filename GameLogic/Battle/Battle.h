//
// Created by adao1003 on 7/1/19.
//

#ifndef HIROLSY_BATTLE_H
#define HIROLSY_BATTLE_H


#include <vector>
#include "BattleFieldPart.h"
#include "../Hero.h"

class Map;
class Battle {
    std::vector<std::vector<BattleFieldPart>> battleField;
    std::vector<std::shared_ptr<Unit>> AttackerUnits;
    std::vector<std::shared_ptr<Unit>> AttackedUnits;
    Hero* AttackerHero;
    Hero* AttackedHero;
    sf::Vector2u selection;
    Player* currentPlayer;
    std::shared_ptr<Unit> currentUnit = nullptr;
    Map* map;
    void removeUnit(std::shared_ptr<Unit> unit);
public:
    Battle(Hero *attackerHero, Hero *attackedHero, Map *map = nullptr);

    void setMap(Map *map);

    void addAttackerUnit(const std::shared_ptr<Unit>& unit);
    void addAttackedUnit(const std::shared_ptr<Unit>& unit);
    void select(unsigned int x, unsigned int y);

    const sf::Vector2u &getSelection() const;

    friend class BattleView;
    void changePlayer();
    void moveUnit();
};


#endif //HIROLSY_BATTLE_H
