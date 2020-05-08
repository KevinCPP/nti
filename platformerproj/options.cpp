#include "options.h"

namespace Options{
    std::unique_ptr<int> FramerateCap;
    std::unique_ptr<bool> FramerateCounter;

    std::unique_ptr<sf::Color> FramerateCounterBackgroundColor;
    std::unique_ptr<sf::Color> FramerateCounterColor;
    std::unique_ptr<int> FramerateCounterFontSize;

    std::unique_ptr<sf::VideoMode> Resolution;

    void setDefaults(){
        FramerateCap = std::make_unique<int>(60);
        FramerateCounter = std::make_unique<bool>(false);
        FramerateCounterBackgroundColor = std::make_unique<sf::Color>(sf::Color(96, 96, 96));
        FramerateCounterColor = std::make_unique<sf::Color>(sf::Color::Green);
        FramerateCounterFontSize = std::make_unique<int>(12);
        Resolution = std::make_unique<sf::VideoMode>(sf::VideoMode::getDesktopMode());
    }
}
