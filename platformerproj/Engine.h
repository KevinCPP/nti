#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Engine{

    enum GameState{
        MainMenu = 0,
        Play = 1,
        Paused = 2,
        Exit = 3
    };

    extern std::unique_ptr<GameState> gameStatus;
    extern std::unique_ptr<sf::RenderWindow> window;
    extern std::unique_ptr<sf::Font> defaultFont;
    extern std::unique_ptr<sf::Clock> FramerateClock;
    extern int yResolution;
    extern int xResolution;

    void updateOptions();

    void drawGame();

    sf::Vector2f getMousePos();
    bool initialize();
    float getFPS();
}

#endif // ENGINE_H_INCLUDED
