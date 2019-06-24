//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_ROAD_H
#define HIROLSY_ROAD_H


#include "Field.h"

class Road : public Field {
public:
    Road();

    void resetCost() override;
};


#endif //HIROLSY_ROAD_H
