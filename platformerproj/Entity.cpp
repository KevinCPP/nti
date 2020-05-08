#include "Entity.h"


Entity::Entity(const std::string& fileName, const sf::IntRect& area){
    texture.loadFromFile(fileName, area);
    eSprite.setTexture(texture);
}

