#include "Alien.h"
#include "frogger.h"
#include "engine.h"
#include <stdlib.h>  
#include <time.h> 
// ---------------------------------------------------------------------------------
/*
RUN - jogo rodando normal

*/

Alien::Alien(int velYAlien)
{
    //type = TYPEOBJ
    tileset = new TileSet("Resources/alien.png", 56, 56, 1, 1);
    anim = new Animation(tileset, 0.120f, true);
    velY = velYAlien;
    /*uint seqLeft[1] = {1};
    uint seqRight[1] = { 2 };
    uint seqUp[1] = { 0 };
    uint seqDown[1] = { 3 };
    anim->Add(LEFT, seqLeft, 1);
    anim->Add(RIGHT, seqRight, 1);
    anim->Add(DOWN, seqDown, 1);
    anim->Add(UP, seqUp, 1);*/
    //mudar para forma de alto desempenho
    MoveTo(float(rand() % window->Width()), 0);
    /*BBox(new Rect(-1 * tileset->TileWidth() / 2,
        -1 * tileset->TileHeight() / 2,
        tileset->TileWidth() / 2,
        tileset->TileHeight() / 2
        ));*/
    BBox(new Rect(-1 * 56 / 2,
        -1 * 56 / 2,
        //0,
        56 / 2,
        56 / 2
    ));
    type = ALIEN;
    //statePlayer = RUN;
}

// ---------------------------------------------------------------------------------

Alien::~Alien()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Alien::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

void Alien::Update()
{
   
    //anim->Select(stateDirectionPlayer);
    Translate(0, velY * gameTime);
    if (Y() - tileset->TileHeight() >= window->Height()) MoveTo(float(rand() % window->Width()), -1.0f* tileset->TileHeight());
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------
