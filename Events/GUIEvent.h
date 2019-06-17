//
// Created by adao1003 on 6/11/19.
//

#ifndef HIROLSY_GUIEVENT_H
#define HIROLSY_GUIEVENT_H


#include "Event.h"
#include "../GUI/GUIObject/Button.h"
#include "../GUI/GUIObject/GUIObject.h"
class GUIEvent: public Event {
     GUIObject& sender;
public:
    GUIEvent(Type type, GUIObject &guiObject);
};


#endif //HIROLSY_GUIEVENT_H
