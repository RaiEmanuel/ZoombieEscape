
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "GameOver.h"
#include "SplashScreen.h"

// -----------------------------------------------------------------------------

Scene* GameOver::scene = nullptr;

// -----------------------------------------------------------------------------

GameOver::GameOver(int points) {
    pointsPlayer = points;
}

void GameOver::Init()
{
    // cria cena do jogo
    scene = new Scene();
    //fica depois dos botes para preferência na colisão
    switch (pointsPlayer) {
    case 0:
        bg = new BackgroundGameOver("Resources/bggameover0.png");
        break;
    case 1:
        bg = new BackgroundGameOver("Resources/bggameover1.png");
        break;
    case 2:
        bg = new BackgroundGameOver("Resources/bggameover2.png");
        break;
    case 3:
        bg = new BackgroundGameOver("Resources/bggameover3.png");
        break;
    case 4:
        bg = new BackgroundGameOver("Resources/bggameover4.png");
        break;
    }
    
    scene->Add(bg, STATIC);
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();

    if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        keyCtrlReturn = false;
        Engine::Next<SplashScreen>();
    }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    scene->Draw();
    scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete scene;
}

