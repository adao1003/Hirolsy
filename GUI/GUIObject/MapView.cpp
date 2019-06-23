//
// Created by adao1003 on 6/19/19.
//

#include "MapView.h"
#include <SFML/Graphics/Sprite.hpp>
MapView::MapView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
                 const std::function<void(GUIObject &, StateMachine &)> &onClick) :  GUIObject(window, sf::Sprite(),
                                                                                                        vec, onClick),map(map) {
    renderTexture.create(1080,800);
    sprite = sf::Sprite(renderTexture.getTexture());
    sprite.setPosition(vec);
    map.generatorTileMap();
}

void MapView::draw() {
    renderTexture.clear();
    auto temp = sf::Sprite(map.getTileMap()->getTexture());
    renderTexture.draw(temp);
    renderTexture.display();
    GUIObject::draw();
}
