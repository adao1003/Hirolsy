//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MOUNTAINS_H
#define HIROLSY_MOUNTAINS_H


#include "Field.h"

class Mountains: public Field {
public:
    void resetCost() override;

public:
    Mountains();
};


#endif //HIROLSY_MOUNTAINS_H
