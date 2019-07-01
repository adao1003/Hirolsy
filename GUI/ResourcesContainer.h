//
// Created by adao1003 on 6/3/19.
//

#ifndef HIROLSY_RESOURCESCONTAINER_H
#define HIROLSY_RESOURCESCONTAINER_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <filesystem>
#include <SFML/Graphics/Font.hpp>
#include <unordered_map>

class ResourcesContainer {
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> fonts;
    ResourcesContainer();
    ~ResourcesContainer() = default;
    sf::Texture emptyTexture;
    sf::Font emptyFont;
public:
    ResourcesContainer(const ResourcesContainer& t) = delete;
    static ResourcesContainer& getInstance()
    {
        static ResourcesContainer sig;
        return sig;
    }
    sf::Texture& getTexture(const std::string &string);
    sf::Font& getFont(const std::string &string);

};


#endif //HIROLSY_RESOURCESCONTAINER_H
