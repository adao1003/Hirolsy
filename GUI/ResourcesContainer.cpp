//
// Created by adao1003 on 6/3/19.
//

#include <iostream>
#include "ResourcesContainer.h"

ResourcesContainer::ResourcesContainer() {
    for (auto &p: std::filesystem::directory_iterator("img"))
    {
        sf::Texture temp ;
        if (temp.loadFromFile(p.path().string()))
            textures.insert(std::pair<std::string, sf::Texture>(p.path().filename().string(), std::move(temp)));
    }
    std::cout << textures.bucket_count() << std::endl;
}

sf::Texture &ResourcesContainer::getTexture(std::string string) {
    try
    {
        return textures.at(string);
    }
    catch (std::out_of_range& e )
    {
        std::clog << "Texture not found: " << string << std::endl;
        return empty;
    }
}
