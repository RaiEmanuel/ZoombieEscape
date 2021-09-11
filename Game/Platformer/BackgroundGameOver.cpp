#include "BackgroundGameOver.h"
#include "frogger.h"
#include "engine.h"

// ---------------------------------------------------------------------------------

BackgroundGameOver::BackgroundGameOver(string fileName)
{
    bgSprite = new Sprite(fileName);
}

// ---------------------------------------------------------------------------------

BackgroundGameOver::~BackgroundGameOver()
{
    delete bgSprite;
}

// -------------------------------------------------------------------------------

void BackgroundGameOver::Update()
{}

// -------------------------------------------------------------------------------

void BackgroundGameOver::Draw()
{
    bgSprite->Draw(window->Width() / 2.0f, window->Height() / 2.0f, Layer::BACK);
}

void BackgroundGameOver::OnCollision(Object* obj)
{}

void BackgroundGameOver::setSprite(string fileName) {
    delete bgSprite;
    bgSprite = new Sprite(fileName);
}

// -------------------------------------------------------------------------------

