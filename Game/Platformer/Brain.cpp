/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Brain.h"
#include "frogger.h"

// ---------------------------------------------------------------------------------
Brain::Brain()
{
    tileset = new TileSet("Resources/brain.png", 28, 28, 1, 1);
    anim = new Animation(tileset, 0.120f, true);

    //20x20 eh bbox do player
    /*BBox(new Rect(-1 * tileset->Width() / 2.0f, -1 * tileset->Height() / 2.0f,
        tileset->Width() / 2.0f, tileset->Height() / 2.0f
    ));*/
    BBox(new Rect(-1 * 28 / 2.0f, -1 * 28 / 2.0f,
        28 / 2.0f, 28 / 2.0f
    ));
    type = BRAIN;
}

// ---------------------------------------------------------------------------------

Brain::~Brain()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Brain::OnCollision(Object* obj)
{
    //Translate(0, -100);
    //Platformer::scene->Remove();

}

// ---------------------------------------------------------------------------------

void Brain::Update()
{
   
}

// ---------------------------------------------------------------------------------