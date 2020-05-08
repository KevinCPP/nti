#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

struct Entity{
    sf::Sprite eSprite;
    sf::Texture texture;

    Entity(const std::string& fileName, const sf::IntRect& area);

};

#endif // ENTITY_H_INCLUDED
