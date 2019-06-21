//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MAPLOADER_H
#define HIROLSY_MAPLOADER_H


#include "Map.h"
#include <string>

class MapLoader {
public:
    virtual Map loadMap(const std::string& path) = 0;
};


#endif //HIROLSY_MAPLOADER_H
