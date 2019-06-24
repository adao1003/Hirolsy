//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_GRASS_H
#define HIROLSY_GRASS_H


#include "Field.h"

class Grass: public Field {
public:
    void resetCost() override;

public:
    Grass();
};


#endif //HIROLSY_GRASS_H
