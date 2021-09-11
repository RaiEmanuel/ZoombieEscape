
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    Sprite* bgSprite;

public:
    bool activeWater = true; //se água ativa então ela pode fazer player perder quando em contato
    Background(string fileName);                       // construtor
    ~Background();                      // destrutor

    void setSprite(string fileName);      // atualiza o sprite com nova imagem
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolução da colisão
}; 

// ---------------------------------------------------------------------------------

#endif