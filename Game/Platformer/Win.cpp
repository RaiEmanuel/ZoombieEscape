
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "Win.h"
#include "SplashScreen.h"

// -----------------------------------------------------------------------------

Scene* Win::scene = nullptr;

// -----------------------------------------------------------------------------

Win::Win(int points) {
    pointsPlayer = points;
}

void Win::Init()
{
    // cria cena do jogo
    scene = new Scene();
    //fica depois dos botes para preferência na colisão
    switch (pointsPlayer) {
    case 0:
        bg = new BackgroundGameOver("Resources/bgwin0.png");
        break;
    case 1:
        bg = new BackgroundGameOver("Resources/bgwin1.png");
        break;
    case 2:
        bg = new BackgroundGameOver("Resources/bgwin2.png");
        break;
    case 3:
        bg = new BackgroundGameOver("Resources/bgwin3.png");
        break;
    case 4:
        bg = new BackgroundGameOver("Resources/bgwin4.png");
        break;
    }

    scene->Add(bg, STATIC);
}

// ------------------------------------------------------------------------------

void Win::Update()
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

void Win::Draw()
{
    scene->Draw();
    scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Win::Finalize()
{
    delete scene;
}

