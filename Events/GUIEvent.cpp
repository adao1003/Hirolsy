//
// Created by adao1003 on 6/11/19.
//

#include "GUIEvent.h"

GUIEvent::GUIEvent(Event::Type type, GUIObject &guiObject) : Event(type), guiObject(guiObject) {}
