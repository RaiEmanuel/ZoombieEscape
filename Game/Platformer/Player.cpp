#include "Player.h"
#include "frogger.h"
#include "engine.h"
#include "GameOver.h"
#include <sstream>
using namespace std;
// ---------------------------------------------------------------------------------
/*
RUN - jogo rodando normal

*/

Player::Player()
{
    //type = TYPEOBJ
    tileset = new TileSet("Resources/spriteSheetPlayer.png", 56, 56, 4, 4);
    anim = new Animation(tileset, 0.120f, true);
    uint seqLeft[1] = {1};
    uint seqRight[1] = { 2 };
    uint seqUp[1] = { 0 };
    uint seqDown[1] = { 3 };
    anim->Add(LEFT, seqLeft, 1);
    anim->Add(RIGHT, seqRight, 1);
    anim->Add(DOWN, seqDown, 1);
    anim->Add(UP, seqUp, 1);
    MoveTo(window->CenterX(), window->CenterY() + 250);
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
    type = PLAYER;
    //statePlayer = RUN;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->type == FRUIT) {
        Frogger::scene->Remove(obj, STATIC);
        ++points;
    }

    //essa colisão é analisada primeiro devido a ordem de adição na scene
    if (obj->type == BOAT) {
        boat = (Boat*)obj;
    }

    if (obj->type == WATER && boat == nullptr) {
        Background *bg = (Background*) obj;
        
        //água ativa faz player perder em contato com a água
        if(bg->activeWater)
            statePlayer = LOSE;
        
            
    }
    if (obj->type == ALIEN) {
        statePlayer = LOSE;
    }

    if (obj->type == CAR) 
    {

        Rect* rBBox = (Rect*)obj->BBox();

        // colisão pela esqueda
        if (x + tileset->TileWidth() <= obj->X())
        {
            Translate(-5 * velX * gameTime, 0);
        }
        else
        {
            // colisão pela direita
            if ( obj->X()+ rBBox->right <= x)
            {
                Translate(5 * velX * gameTime, 0);
            }
            else
            {
                
                // colisão por baixo
                if (y >= obj->Y() + rBBox->bottom)
                {
                    Translate(0, 2 * velX * gameTime);
                }
                else
                {
                    // colisão por cima
                    Translate(0, -2 * velX * gameTime);
                }
            }

        }

        //if (x > tileset->TileWidth() / 1.5)
        //{
            
        //}

















        if (statePlayer == CONFUSED)
        {
            statePlayer = LOSE;
        }else
        { 
            statePlayer = CONFUSED;
        }

        
    }

    if (obj->type == BRAIN)
    {
        statePlayer = WIN;
    }

}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    /* verifica se está colindindo com bote e desloca junto*/
    if (boat != nullptr) {
        Translate(boat->velX * gameTime, 0);
    }
    boat = nullptr;//garante que só tem o bote se estiver colidindo
    //OutputDebugString("==================== tempo 1s");

    if (statePlayer != CONFUSED)
    {
        /* Controla tecla para cima */
        if (keyCtrlUp && window->KeyDown(VK_UP)) {
            keyCtrlUp = false;
            stateDirectionPlayer = UP;
            if (y > tileset->TileHeight() / 1.5)
            {
                Translate(0, -velY * gameTime);
            }
        }
        if (window->KeyUp(VK_UP)) keyCtrlUp = true;

        /* Controla tecla para baixo */
        if (keyCtrlDown && window->KeyDown(VK_DOWN)) {
            keyCtrlDown = false;
            stateDirectionPlayer = DOWN;
            if (y  < window->Height()-tileset->TileHeight()/1.5)
            {
                Translate(0, velY * gameTime);
            }
            
        }
        if (window->KeyUp(VK_DOWN)) keyCtrlDown = true;

        /* Controla tecla para baixo */
        if (keyCtrlLeft && window->KeyDown(VK_LEFT)) {
            keyCtrlLeft = false;
            stateDirectionPlayer = LEFT;
            if (x >  tileset->TileWidth() / 1.5)
            {
                Translate(-velX * gameTime, 0);
            }
        }
        if (window->KeyUp(VK_LEFT)) keyCtrlLeft = true;

        /* Controla tecla para direita */
        if (keyCtrlRight && window->KeyDown(VK_RIGHT)) {
            keyCtrlRight = false;
            stateDirectionPlayer = RIGHT;
            if (x < window->Width() - tileset->TileWidth() / 1.5)
            {
                Translate(velX * gameTime, 0);
            }
        }
        if (window->KeyUp(VK_RIGHT)) keyCtrlRight = true;
    }
    else
    {
        /* Controla tecla para cima */
        if (keyCtrlUp && window->KeyDown(VK_UP)) {
            keyCtrlUp = false;
            stateDirectionPlayer = DOWN;
            if (y < window->Height() - tileset->TileHeight() / 1.5)
            {
                Translate(0, velY * gameTime);
            }
        }
        if (window->KeyUp(VK_UP)) keyCtrlUp = true;

        /* Controla tecla para baixo */
        if (keyCtrlDown && window->KeyDown(VK_DOWN)) {
            keyCtrlDown = false;
            stateDirectionPlayer = UP;
            if (y > tileset->TileHeight() / 1.5)
            {
                Translate(0, -velY * gameTime);
            }
        }
        if (window->KeyUp(VK_DOWN)) keyCtrlDown = true;

        /* Controla tecla para baixo */
        if (keyCtrlLeft && window->KeyDown(VK_LEFT)) {
            keyCtrlLeft = false;
            stateDirectionPlayer = RIGHT;
            if (x < window->Width() - tileset->TileWidth() / 1.5)
            {
                Translate(velX * gameTime, 0);
            }
        }
        if (window->KeyUp(VK_LEFT)) keyCtrlLeft = true;

        /* Controla tecla para direita */
        if (keyCtrlRight && window->KeyDown(VK_RIGHT)) {
            keyCtrlRight = false;
            stateDirectionPlayer = LEFT;
            if (x > tileset->TileWidth() / 1.5)
            {
                Translate(-velX * gameTime, 0);
            }
        }
        if (window->KeyUp(VK_RIGHT)) keyCtrlRight = true;
    }

    
    anim->Select(stateDirectionPlayer);
    anim->NextFrame();
}
// --------------------------------------------------------------------------------