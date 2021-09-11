#include "BackgroundSplashScreen.h"
#include "frogger.h"
#include "engine.h"

// ---------------------------------------------------------------------------------

BackgroundSplashScreen::BackgroundSplashScreen(string fileName)
{
    bgSprite = new Sprite(fileName);
}

// ---------------------------------------------------------------------------------

BackgroundSplashScreen::~BackgroundSplashScreen()
{
    delete bgSprite;
}

// -------------------------------------------------------------------------------

void BackgroundSplashScreen::Update()
{}

// -------------------------------------------------------------------------------

void BackgroundSplashScreen::Draw()
{
    bgSprite->Draw(window->Width() / 2.0f, window->Height() / 2.0f, Layer::BACK);
}

void BackgroundSplashScreen::OnCollision(Object* obj)
{}

void BackgroundSplashScreen::setSprite(string fileName) {
    delete bgSprite;
    bgSprite = new Sprite(fileName);
}

// -------------------------------------------------------------------------------

