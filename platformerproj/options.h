#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <memory>
#include <SFML/Graphics.hpp>

namespace Options{
    extern std::unique_ptr<int> FramerateCap;
    extern std::unique_ptr<bool> FramerateCounter;

    extern std::unique_ptr<sf::Color> FramerateCounterBackgroundColor;
    extern std::unique_ptr<sf::Color> FramerateCounterColor;
    extern std::unique_ptr<int> FramerateCounterFontSize;

    extern std::unique_ptr<sf::VideoMode> Resolution;

    void setDefaults();
}

#endif // OPTIONS_H_INCLUDED
