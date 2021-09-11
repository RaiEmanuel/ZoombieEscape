
#include "Background.h"
#include "frogger.h"
#include "engine.h"

// ---------------------------------------------------------------------------------

Background::Background(string fileName)
{
    bgSprite = new Sprite(fileName);
    //tileset = new TileSet(fileName, 703, 632, 2,2);
    //anim = new Animation(tileset, 0.120f, true);
    //uint seqNormal[1] = { 0 };
    //uint seqFreeze[1] = { 1 };
    
    //anim->Add(FREEZE, seqFreeze, 1);
    //anim->Add(NORMAL, seqNormal, 1);
    MoveTo(0,0);
    BBox(new Rect(0.0f,90.0f,float(window->Width()),90+260.0f));
    type = WATER;
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete anim;
    delete tileset;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    //anim->Select(stateWater);
    //anim->NextFrame();
    //anim->Select(stateWater);
    //anim->NextFrame();
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

