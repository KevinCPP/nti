#include "Engine.h"

int main(){
    Engine::initialize();

    while(Engine::window->isOpen()){
        sf::Event event;
        while(Engine::window->pollEvent(event)){
            if(event.type == sf::Event::Closed)
                Engine::window->close();
        }

        Engine::window->clear();

        Engine::drawGame();

        Engine::window->display();
    }
}
