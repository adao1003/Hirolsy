//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAPVIEW_H
#define HIROLSY_MAPVIEW_H


#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GUIObject.h"
#include "../../GameLogic/Map.h"

class MapView: public GUIObject {
    Map& map;
    std::unique_ptr<sf::RenderTexture> renderTexture = std::make_unique<sf::RenderTexture>();
    static void onRightClick(GUIObject& g, StateMachine& s);
    static void onLeftClick(GUIObject& g, StateMachine& s);
public:
    sf::Vector2i poz = sf::Mouse::getPosition();
    void draw() override;
    MapView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
            const std::function<void(GUIObject &, StateMachine &)> &onClick = MapView::onLeftClick);
    const sf::Vector2i &getPoz() const;
    friend void onLeftClick(GUIObject& g, StateMachine& s);
};


#endif //HIROLSY_MAPVIEW_H
