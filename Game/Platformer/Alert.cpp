
#include "Alert.h"
#include "frogger.h"
#include "engine.h"

// ---------------------------------------------------------------------------------

Alert::Alert(string fileName)
{
   // bgSprite = new Sprite(fileName);
    tileset = new TileSet(fileName, 105, 80, 3,3);
    anim = new Animation(tileset, 0.120f, true);
    uint seqConfusedControl[1] = { 2 };
    uint seqFreeze[1] = { 1 };
    uint seqNone[1] = { 0 };

    anim->Add(CONFUSEDCONTROLALERT, seqConfusedControl, 1);
    anim->Add(FREEZEWATERALERT, seqFreeze, 1);
    anim->Add(NONE, seqNone, 1);
    
    MoveTo(tileset->TileWidth() / 2.0f, tileset->TileHeight() / 2.0f);
    //BBox(new Rect(0.0f, 90.0f, float(window->Width()), 90 + 260.0f));
    type = ALERT;
}

// ---------------------------------------------------------------------------------

Alert::~Alert()
{
    delete anim;
    delete tileset;
}

// -------------------------------------------------------------------------------

void Alert::Update()
{
    Translate(gameTime * velX, 0);
   // if (stateAlert != NONE) {
        anim->Select(stateAlert);
        anim->NextFrame();
   // }
    
    //if (X() >= 350) scene->D
    //anim->Select(stateWater);
    //anim->NextFrame();
}

// -------------------------------------------------------------------------------

void Alert::OnCollision(Object* obj)
{
}

/*void Alert::setSprite(string fileName) {
    delete bgSprite;
    bgSprite = new Sprite(fileName);
}*/

// -------------------------------------------------------------------------------

