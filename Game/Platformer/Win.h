#ifndef _WIN_H_
#define _WIN_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "BackgroundGameOver.h"

// ------------------------------------------------------------------------------

class Win : public Game
{
private:
    BackgroundGameOver* bg = nullptr;   // pano de fundo
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espaço
    int pointsPlayer = 0;
public:
    static Scene* scene;           // gerenciador de cena
    Win(int points);

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif