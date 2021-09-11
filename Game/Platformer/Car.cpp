/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o carro
//
**********************************************************************************/

#include "Car.h"
#include "frogger.h"

// ---------------------------------------------------------------------------------
Car::Car()
{
    tileset = new TileSet("Resources/carro.png", 111, 42, 1, 1);
    anim = new Animation(tileset, 0.120f, true);

    //20x20 eh bbox do player
    /*BBox(new Rect(-1 * tileset->Width() / 2.0f, -1 * tileset->Height() / 2.0f,
        tileset->Width() / 2.0f, tileset->Height() / 2.0f
    ));*/
    BBox(new Rect(-1 * 111 / 2.0f, -1 * 42 / 2.0f,
        111 / 2.0f, 42 / 2.0f
    ));
    type = CAR;
}

// ---------------------------------------------------------------------------------

Car::~Car()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Car::OnCollision(Object* obj)
{
    //Translate(0, -100);
    //Platformer::scene->Remove();

}

// ---------------------------------------------------------------------------------

void Car::Update()
{
    Translate(velX * gameTime, 0);

    if (X() + tileset->Width() <= 0) {
        MoveTo(window->Width() + tileset->TileWidth() / 2.0f, Y());
    }
}

// ---------------------------------------------------------------------------------