//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAPVIEW_H
#define HIROLSY_MAPVIEW_H


#include <SFML/Graphics/RenderTexture.hpp>
#include "GUIObject.h"
#include "../../GameLogic/Map.h"

class MapView: public GUIObject {
    Map& map;
    sf::RenderTexture renderTexture;
public:
    void draw() override;

    MapView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
            const std::function<void(GUIObject &, StateMachine &)> &onClick = GUIObject::empty);
};


#endif //HIROLSY_MAPVIEW_H
