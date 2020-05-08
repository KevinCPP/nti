#include "OptionsMenu.h"
#include "Engine.h"
#include "TextButton.h"
#include "options.h"

#include <string>
#include <sstream>
#include <iostream>

namespace OptionsMenu{

    std::unique_ptr<TextButton> FramerateButton;
    std::array<int, 8> framerateOptions = {60, 72, 90, 120, 144, 165, 240, 9001};
    std::unique_ptr<int> currentSelection;

    std::unique_ptr<TextButton> FPSCountVisibleButton;
    std::unique_ptr<TextButton> BackButton;

    void initialize(){
        int fontSize = Engine::yResolution/30;
        int y;

        FramerateButton = std::make_unique<TextButton>(sf::Vector2f(10, 50), sf::Color::Yellow, sf::Color::Red, L"FrameRate Cap: 60", fontSize);

        y = FramerateButton->getPosition().y + fontSize*1.2;

        FPSCountVisibleButton = std::make_unique<TextButton>(sf::Vector2f(10, y), sf::Color::Yellow, sf::Color::Red, L"FPS Counter: Off", fontSize);


        BackButton = std::make_unique<TextButton>(sf::Vector2f(10, Engine::yResolution - fontSize*2.2), sf::Color::Yellow, sf::Color::Red, L"Back", fontSize);
        currentSelection = std::make_unique<int>(0);

    }

    void draw(){
        if(FramerateButton)
            FramerateButton->draw();
        if(FPSCountVisibleButton)
            FPSCountVisibleButton->draw();
        if(BackButton)
            BackButton->draw();
    }

    void checkInteraction(){
        if(FramerateButton){
            if(FramerateButton->pollClicked()){

                *currentSelection += 1;

                if(framerateOptions.size() <= *currentSelection)
                    *currentSelection = 0;

                *Options::FramerateCap = framerateOptions[*currentSelection];

                std::wstringstream s;
                s << L"FrameRate Cap: " << *Options::FramerateCap;
                FramerateButton->setText(s.str().c_str());

                Engine::updateOptions();
            }
        }
        if(FPSCountVisibleButton){
            if(FPSCountVisibleButton->pollClicked()){
                *Options::FramerateCounter = !*Options::FramerateCounter;

                if(*Options::FramerateCounter)
                    FPSCountVisibleButton->setText(L"FPS Counter: On");
                else
                    FPSCountVisibleButton->setText(L"FPS Counter: Off");

                Engine::updateOptions();

            }
        }
        if(BackButton){
            if(BackButton->pollClicked()){
                *Engine::gameStatus = Engine::GameState::MainMenu;

            }
        }
    }

}
