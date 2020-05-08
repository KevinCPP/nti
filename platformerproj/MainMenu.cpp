#include "MainMenu.h"
#include "TextButton.h"

#include <iostream>
#include "TextButton.h"

namespace MainMenu{

    std::unique_ptr<TextButton> playButton = nullptr;
    std::unique_ptr<TextButton> optionsButton = nullptr;
    std::unique_ptr<TextButton> quitButton = nullptr;
    std::unique_ptr<sf::Text> title = nullptr;

    void initialize(){

            int fontSize = Engine::yResolution/20;

            playButton = std::make_unique<TextButton>(sf::Vector2f(10, fontSize*4), sf::Color::White, sf::Color::Red, L"Play", fontSize);
            optionsButton = std::make_unique<TextButton>(sf::Vector2f(10, playButton->getPosition().y + fontSize*1.2), sf::Color::White, sf::Color::Red, L"Options", fontSize);
            quitButton = std::make_unique<TextButton>(sf::Vector2f(10, optionsButton->getPosition().y + fontSize*1.2), sf::Color::White, sf::Color::Red, L"Quit", fontSize);

            title = std::make_unique<sf::Text>();

            title->setString("Kevin Jumps");
            title->setFillColor(sf::Color(255, 64, 64));
            title->setFont(*Engine::defaultFont);
            title->setCharacterSize(fontSize*2);
            title->setPosition(sf::Vector2f(10, 40));
    }

    void draw(){
        //make sure pointers are initialized before trying to call a function
        if(playButton)
            playButton->draw();
        if(optionsButton)
            optionsButton->draw();
        if(quitButton)
            quitButton->draw();
        if(title)
            Engine::window->draw(*title);
    }

    void checkInteraction(){
        if(playButton && playButton->pollClicked())
            *Engine::gameStatus = Engine::GameState::Play;
        if(optionsButton && optionsButton->pollClicked())
            *Engine::gameStatus = Engine::GameState::Paused;
        if(quitButton && quitButton->pollClicked())
            *Engine::gameStatus = Engine::GameState::Exit;
    }
}
