//
// Created by adao1003 on 6/3/19.
//

#ifndef HIROLSY_TEXTURESCONTAINER_H
#define HIROLSY_TEXTURESCONTAINER_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>

class TexturesContainer {
    std::vector<sf::Texture> vector;
    TexturesContainer() = default;;
    ~TexturesContainer() = default;;
    TexturesContainer(const TexturesContainer& t) {} ;
public:
    static TexturesContainer getInstance()
    {
        static TexturesContainer sig;
        return sig;
    }

};


#endif //HIROLSY_TEXTURESCONTAINER_H
