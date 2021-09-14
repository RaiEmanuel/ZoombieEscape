
#include "Fruit.h"
#include "frogger.h"

// ---------------------------------------------------------------------------------
Fruit::Fruit(string imageName)
{
    tileset = new TileSet(imageName, 30, 30, 1, 1);
    anim = new Animation(tileset, 0.120f, true);
    MoveTo(window->CenterX(), window->CenterY() + 150);
    //BBox(new Rect(-15,-15,15,15));
    BBox(new Circle(tileset->TileWidth() / 2.0f));
    type = FRUIT;
}

// ---------------------------------------------------------------------------------

Fruit::~Fruit()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Fruit::OnCollision(Object* obj)
{
    
    /*if (obj->type == PLAYER) {
        Platformer::scene->Remove(this, STATIC);//usar remove apenas no update
    }*/
    
    
}

// ---------------------------------------------------------------------------------

void Fruit::Update()
{
   
}

// ---------------------------------------------------------------------------------