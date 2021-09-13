/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o carro
//
**********************************************************************************/

#include "Car.h"
#include "frogger.h"

// ---------------------------------------------------------------------------------
Car::Car()
{
    tileset = new TileSet("Resources/carro.png", 100, 40, 1, 1);
    anim = new Animation(tileset, 0.120f, true);

    //20x20 eh bbox do player
    /*BBox(new Rect(-1 * tileset->Width() / 2.0f, -1 * tileset->Height() / 2.0f,
        tileset->Width() / 2.0f, tileset->Height() / 2.0f
    ));*/
    //BBox(new Rect(-1*tileset->TileWidth()/2.0f, -1 * tileset->TileHeight() / 2.0f, tileset->TileWidth() / 2.0f, tileset->TileHeight() / 2.0f));
    BBox(new Rect(-1*100/2.0f, -1 * 40 / 2.0f, 100 / 2.0f, 40 / 2.0f));
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