/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"
#include "frogger.h"
#include "engine.h"

// ---------------------------------------------------------------------------------

Background::Background(string fileName)
{
    bgSprite = new Sprite(fileName);
    //152 hardcode da alura, +180 porue é a altura da imagem da água
    BBox(new Rect(0.0f,90.0f,float(window->Width()),90+260.0f));
    type = WATER;
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete bgSprite;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    //Engine::Next<GameOver>();
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    bgSprite->Draw(window->Width()/2.0f, window->Height() / 2.0f, Layer::BACK);
}

void Background::OnCollision(Object* obj)
{
}

void Background::setSprite(string fileName) {
    delete bgSprite;
    bgSprite = new Sprite(fileName);
}

// -------------------------------------------------------------------------------

