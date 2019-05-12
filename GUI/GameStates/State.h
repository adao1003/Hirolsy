//
// Created by adao1003 on 5/12/19.
//

#ifndef HIROLSY_STATE_H
#define HIROLSY_STATE_H


class State {
private:
    State* prevState;
public:
    explicit State(State *prevState) : prevState(prevState) {}

};


#endif //HIROLSY_STATE_H
