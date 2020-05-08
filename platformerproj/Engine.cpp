#include "Engine.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "options.h"
#include "FPScounter.h"

#include <windows.h>
#include <iostream>

namespace Engine{
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Font> defaultFont;
    std::unique_ptr<GameState> gameStatus;
    std::unique_ptr<sf::Clock> FramerateClock;

    int xResolution;
    int yResolution;

    bool initialize(){
        Options::setDefaults();
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "test", sf::Style::None);
        defaultFont = std::make_unique<sf::Font>();
        gameStatus = std::make_unique<GameState>(GameState::MainMenu);
        FramerateClock = std::make_unique<sf::Clock>();

        if(!defaultFont->loadFromFile("arial.ttf"))
            return false;

        xResolution = Options::Resolution->width;
        yResolution = Options::Resolution->height;

        MainMenu::initialize();
        OptionsMenu::initialize();

        return true;
    }

    void drawGame(){


        if(*gameStatus == GameState::MainMenu){
            MainMenu::draw();
            MainMenu::checkInteraction();
        } else if(*gameStatus == GameState::Paused){
            OptionsMenu::draw();
            OptionsMenu::checkInteraction();
        } else if(*gameStatus == GameState::Exit){
            window->close();
        } else {
            //draw game here


        }

        if(*Options::FramerateCounter)
            FPScounter::draw();
    }

    void updateOptions(){
        window->setFramerateLimit(*Options::FramerateCap);
    }

    float getFPS(){
        float T = FramerateClock->getElapsedTime().asMicroseconds();
        float framerate = 1000000/T;
        FramerateClock->restart();
        return framerate;
    }

    sf::Vector2f getMousePos(){
        sf::Vector2i mousePos2i = sf::Mouse::getPosition(*window);
        sf::Vector2f mousePos2f;
        mousePos2f.x = (float)mousePos2i.x;
        mousePos2f.y = (float)mousePos2i.y;
        return mousePos2f;
    }
}
