
#ifndef _PLATFORMER_CAR_H_
#define _PLATFORMER_CAR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites


class Car : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima��o do personagem

public:
    float velX = -70; //velocidade do bote

    Car();                           // construtor
    ~Car();                          // destrutor

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Car::Draw() { anim->Draw(x, y, z); }
#endif
