//
// Created by adao1003 on 6/19/19.
//

#include "MapView.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>

MapView::MapView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
                 const std::function<void(GUIObject &, StateMachine &)> &onClick) :  GUIObject(window, sf::Sprite(),
                                                                                                        vec, onClick),map(map) {
    renderTexture->create(1280,800);
    sprite = sf::Sprite(renderTexture->getTexture());
    sprite.setPosition(vec);
    map.generatorTileMap();
    setOnRightClick(MapView::onRightClick);
    auto view = renderTexture->getView();
    std::cout << view.getCenter().x << " " << view.getCenter().y;
}

void MapView::draw() {
    poz = sf::Mouse::getPosition();
    renderTexture->clear();
    auto temp = sf::Sprite(map.getTileMap()->getTexture());
    renderTexture->draw(temp);
    for(auto &it:map.getBuildings())
    {
        renderTexture->draw(it->getSprite());
    }
    for(auto &it:map.getDynamicObjects())
    {
        renderTexture->draw(it->getSprite());
    }
    sf::Sprite sel(ResourcesContainer::getInstance().getTexture("selection.png"));
    sel.setPosition(map.getSelection().x*64, map.getSelection().y*64);
    renderTexture->draw(sel);
    renderTexture->display();
    GUIObject::draw();
}

void MapView::onRightClick(GUIObject &g, StateMachine &s) {
    auto obj = dynamic_cast<MapView*>(&g);
    //static sf::Vector2i poz = sf::Mouse::getPosition();
    auto view = obj->renderTexture->getView();
    sf::Vector2f vec(obj->getPoz().x-sf::Mouse::getPosition().x, obj->getPoz().y-sf::Mouse::getPosition().y );
    view.move(vec);
    obj->renderTexture->setView(view);
    //std::cout << "d" << std::endl;
}

const sf::Vector2i &MapView::getPoz() const {
    return poz;
}

void MapView::onLeftClick(GUIObject &g, StateMachine &s) {
    auto obj = dynamic_cast<MapView*>(&g);
    auto poz = sf::Mouse::getPosition(obj->window);
    auto view = obj->renderTexture->getView();
    auto pozView = obj->sprite.getPosition();
    unsigned int x = (poz.x-pozView.x+(view.getCenter().x-obj->renderTexture->getSize().x/2))/64;
    unsigned int y = (poz.y-pozView.y+(view.getCenter().y-obj->renderTexture->getSize().y/2))/64;
    obj->map.select(x, y);
}
