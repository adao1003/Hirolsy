//
// Created by adao1003 on 6/19/19.
//

#ifndef HIROLSY_MINE_H
#define HIROLSY_MINE_H


#include "../GameObject.h"

class Mine: public GameObject {
    Mine* owner = nullptr;
public:
    Mine(unsigned int x, unsigned int y, const sf::Texture& tex);
};


#endif //HIROLSY_MINE_H
