
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

// ---------------------------------------------------------------------------------
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"
//#include "Sprite.h"

// ---------------------------------------------------------------------------------

enum STATEWATER { NORMAL, FREEZE };
class Background : public Object
{
private:
    Sprite* bgSprite;
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
public:
    bool activeWater = true; //se água ativa então ela pode fazer player perder quando em contato
    STATEWATER stateWater = NORMAL;
    
    Background(string fileName);                       // construtor
    ~Background();                      // destrutor

    void setSprite(string fileName);      // atualiza o sprite com nova imagem
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolução da colisão
}; 

// ---------------------------------------------------------------------------------

#endif