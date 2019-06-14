//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATE_H
#define HIROLSY_STATE_H


#include <vector>
#include <memory>
#include "../GUIObject/GUIObject.h"
#include "../../Events/EventQueue.h"
#include "../StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>
class GUIObject;
class StateMachine;
class State {
protected:
    std::shared_ptr<State> prevState{};
    std::vector<std::shared_ptr<GUIObject>> items;
    StateMachine& stateMachine;
    sf::RenderWindow& window;
    EventQueue& eventQueue;
public:
    explicit State(sf::RenderWindow &window, EventQueue &eventQueue, StateMachine &stateMachine,
                   const std::shared_ptr<State> &prevState = nullptr)
            : prevState(prevState), window(window), eventQueue(eventQueue), stateMachine(stateMachine) {}

    const std::shared_ptr<State> &getPrevState() const;

    void setPrevState(const std::shared_ptr<State> &prevState);

    virtual void render();

    virtual void input();
};



#endif //HIROLSY_STATE_H
