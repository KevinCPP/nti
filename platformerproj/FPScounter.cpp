#include "FPScounter.h"
#include "Engine.h"
#include "options.h"
#include <SFML/Graphics.hpp>

namespace FPScounter{
    sf::RectangleShape background;
    sf::Text fps;

    void draw(){
        fps.setString(std::to_string(Engine::getFPS()));
        fps.setCharacterSize(*Options::FramerateCounterFontSize);
        fps.setFillColor(*Options::FramerateCounterColor);
        fps.setFont(*Engine::defaultFont);
        fps.setPosition(sf::Vector2f(2, 2));

        background.setPosition(sf::Vector2f(0, 0));
        background.setFillColor(*Options::FramerateCounterBackgroundColor);
        background.setSize(sf::Vector2f(fps.getGlobalBounds().width+4, fps.getGlobalBounds().height+12));

        Engine::window->draw(background);
        Engine::window->draw(fps);

    }

}
