
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "SplashScreen.h"

// -----------------------------------------------------------------------------

Scene* SplashScreen::scene = nullptr;

// -----------------------------------------------------------------------------

void SplashScreen::Init()
{
    // cria cena do jogo
    scene = new Scene();
    //fica depois dos botes para preferência na colisão
    bg = new BackgroundSplashScreen("Resources/bgsplashscreen.png");
    scene->Add(bg, STATIC);
}

// ------------------------------------------------------------------------------

void SplashScreen::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();

    if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        keyCtrlReturn = false;
        Engine::Next<Frogger>();
    }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
}

// ------------------------------------------------------------------------------

void SplashScreen::Draw()
{
    scene->Draw();
    scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void SplashScreen::Finalize()
{
    delete scene;
}

