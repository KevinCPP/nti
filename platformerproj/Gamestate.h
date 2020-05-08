#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

namespace GamestateHandler{
    enum GameState{
        mainMenu = 0,
        paused = 1,
        playing = 2,
        death = 3
    };

    void updateGame(GameState s);


}

#endif // GAMESTATE_H_INCLUDED
