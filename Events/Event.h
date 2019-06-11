//
// Created by adao1003 on 6/5/19.
//

#ifndef HIROLSY_EVENT_H
#define HIROLSY_EVENT_H



class Event {
public:
    enum Type {
        None,
        Clicked
    };
    Type type;
    Event(Type type);
};


#endif //HIROLSY_EVENT_H
