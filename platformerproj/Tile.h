#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Tile{
private:
    sf::RectangleShape tile;    //actual rectangle used to represent the tile
    sf::Texture texture;        //tile rectangle's texture

    const char* tileName;   //tile's name

    bool     interactable;  //can you interact with the tile?
    bool     collision;     //does the tile have collision?
    uint32_t itemID;        //a numeric ID to represent the tile

public:

    //constructor:
    Tile(const char* name,      //initializes the name of the tile.
         const uint32_t& ID,    //initializes the tile's numeric ID.
         bool solid,            //initializes the tile's collision variable.
         bool interact);        //initializes the tile's interactable variable.

    //constructor:
    Tile(const char* name,              //initializes the name of the tile.
         const uint32_t& ID,            //initializes the tile's numeric ID.
         bool solid,                    //initializes the tile's collision variable.
         bool interact,                 //initializes the tile's interactable variable.
         const sf::Texture* texture);   //initializes the tile's texture.

    //setter methods:
    void setMapCoordinates(const uint16_t& x, const uint16_t& y);  //sets the tile's map coordinates
    void setTexture(const sf::Texture* texture);                    //setter method for the tile's texture
    void setInteractable(bool interact);                            //setter method for tile's interactable variable.
    void setCollision(bool solid);                                  //setter method for tile's collision.

    //getter methods:
    uint32_t  getItemID();       //returns the numeric ID representing the tile.
    bool      isInteractable();  //returns the interactable var.
    bool      hasCollision();    //returns the collision var.

    void draw();    //draws the tile to the screen
};

#endif // TILE_H_INCLUDED
