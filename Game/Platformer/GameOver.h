#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "BackgroundGameOver.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    BackgroundGameOver* bg = nullptr;   // pano de fundo
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espaço
    int pointsPlayer = 0;
public:
    static Scene* scene;           // gerenciador de cena
    GameOver(int points);

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif