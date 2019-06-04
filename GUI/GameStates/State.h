//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATE_H
#define HIROLSY_STATE_H


#include <vector>
#include <memory>
#include "../GUIObject/GUIObject.h"
class GUIObject;
class State {
private:
    std::shared_ptr<State> prevState{};
    std::vector<std::shared_ptr<GUIObject>> items;
    sf::Window& window;
public:
    explicit State(const std::shared_ptr <State> &prevState, sf::Window& window) : prevState(prevState), window(window) {}

    virtual void render()=0;
};


#endif //HIROLSY_STATE_H
