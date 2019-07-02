//
// Created by adao1003 on 7/2/19.
//

#ifndef HIROLSY_BATTLEVIEW_H
#define HIROLSY_BATTLEVIEW_H


#include "GUIObject.h"
#include "../../GameLogic/Map.h"

class BattleView: public GUIObject {
    Map& map;
    sf::Sprite sprite;
    std::unique_ptr<sf::RenderTexture> renderTexture = std::make_unique<sf::RenderTexture>();
    static void onLeftClick(GUIObject &g, StateMachine &s);
public:
    BattleView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
               const std::function<void(GUIObject &, StateMachine &)> &onClick = BattleView::onLeftClick);

    void draw() override;

    bool isMouseHover() override;
};


#endif //HIROLSY_BATTLEVIEW_H
