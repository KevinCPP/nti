#include "Tile.h"
#include "Engine.h"

//constructors:
Tile::Tile(const char* name, const uint32_t& ID, bool solid, bool interact){
    tileName = name;
    itemID = ID;
    collision = solid;
    interactable = interact;

    tile.setSize(sf::Vector2f(40, 40));
}

Tile::Tile(const char* name, const uint32_t& ID, bool solid, bool interact, const sf::Texture* tx){
    tileName = name;
    itemID = ID;
    collision = solid;
    interactable = interact;

    tile.setSize(sf::Vector2f(40, 40));
    texture = *tx;
    tile.setTexture(&texture);
}

//setter methods:

void Tile::setTexture(const sf::Texture* tx){
    texture = *tx;
    tile.setTexture(&texture);
}

void Tile::setInteractable(bool interact){
    interactable = interact;
}

void Tile::setCollision(bool solid){
    collision = solid;
}

//getter methods:

uint32_t Tile::getItemID(){
    return itemID;
}

bool Tile::isInteractable(){
    return interactable;
}

bool Tile::hasCollision(){
    return collision;
}

//draws the tile to the window.

void Tile::draw(){
    Engine::window->draw(tile);
}
