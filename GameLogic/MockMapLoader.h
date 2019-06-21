//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MOCKMAPLOADER_H
#define HIROLSY_MOCKMAPLOADER_H


#include "MapLoader.h"

class MockMapLoader: public MapLoader {
public:
    Map loadMap(const std::string &path) override;
};


#endif //HIROLSY_MOCKMAPLOADER_H
