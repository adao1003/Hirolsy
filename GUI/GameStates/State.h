//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATE_H
#define HIROLSY_STATE_H


#include <vector>
#include <memory>
#include "../GUIObject/GUIObject.h"
#include "../StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>
class GUIObject;
class StateMachine;
class State {
protected:
    std::shared_ptr<State> prevState{};
    std::vector<std::shared_ptr<GUIObject>> items;
    std::shared_ptr<GUIObject> activeObject = nullptr;
    StateMachine& stateMachine;
    sf::RenderWindow& window;
public:
    explicit State(sf::RenderWindow &window, StateMachine &stateMachine,
                   const std::shared_ptr<State> &prevState = nullptr)
            : prevState(prevState), window(window), stateMachine(stateMachine) {}

    const std::shared_ptr<State> &getPrevState() const;
    void setPrevState(const std::shared_ptr<State> &prevState);
    virtual void render();
    virtual void input();
};



#endif //HIROLSY_STATE_H
