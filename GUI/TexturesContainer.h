//
// Created by adao1003 on 6/3/19.
//

#ifndef HIROLSY_TEXTURESCONTAINER_H
#define HIROLSY_TEXTURESCONTAINER_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <filesystem>
class TexturesContainer {
    std::map<std::string, sf::Texture> textures;
    TexturesContainer();
    ~TexturesContainer() = default;
    sf::Texture empty;
public:
    TexturesContainer(const TexturesContainer& t) = delete;
    static TexturesContainer& getInstance()
    {
        static TexturesContainer sig;
        return sig;
    }
    sf::Texture& getTexture(std::string string);

};


#endif //HIROLSY_TEXTURESCONTAINER_H
