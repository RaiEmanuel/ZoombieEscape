#ifndef _SplashScreen_H_
#define _SplashScreen_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "BackgroundSplashScreen.h"

// ------------------------------------------------------------------------------

class SplashScreen : public Game
{
private:
    BackgroundSplashScreen* bg = nullptr;   // pano de fundo
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espaço

public:
    static Scene* scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif