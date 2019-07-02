//
// Created by adao1003 on 7/2/19.
//

#include <SFML/Window/Mouse.hpp>
#include "BattleView.h"

BattleView::BattleView(sf::RenderWindow &window, const sf::Vector2f &vec, Map &map,
                       const std::function<void(GUIObject &, StateMachine &)> &onClick):GUIObject(window,
        vec, onClick), map(map) {
    renderTexture->create(1280,800);
    sprite = sf::Sprite(renderTexture->getTexture());
    sprite.setPosition(vec);
}

void BattleView::draw() {
    auto battle = map.getCurrentBattle().get();
    for(auto & it :battle->battleField)
        for(auto& it0:it)
            renderTexture->draw(it0.getSprite());
    for(auto&it:battle->AttackedUnits)
        renderTexture->draw(it->getSprite());
    for(auto&it:battle->AttackerUnits)
        renderTexture->draw(it->getSprite());
    sf::Sprite sel(ResourcesContainer::getInstance().getTexture("selection.png"));
    sel.setPosition(map.getCurrentBattle()->getSelection().x*64, map.getCurrentBattle()->getSelection().y*64);
    renderTexture->draw(sel);
    renderTexture->display();
    window.draw(sprite);
}

bool BattleView::isMouseHover() {
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

void BattleView::onLeftClick(GUIObject &g, StateMachine &s) {
    auto obj = dynamic_cast<BattleView*>(&g);
    auto poz = sf::Mouse::getPosition(obj->window);
    auto view = obj->renderTexture->getView();
    auto pozView = obj->sprite.getPosition();
    unsigned int x = (poz.x-pozView.x+(view.getCenter().x-obj->renderTexture->getSize().x/2))/64;
    unsigned int y = (poz.y-pozView.y+(view.getCenter().y-obj->renderTexture->getSize().y/2))/64;
    obj->map.getCurrentBattle()->select(x, y);
}
