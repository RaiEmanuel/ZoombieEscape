
#ifndef _PLATFORMER_CAR_H_
#define _PLATFORMER_CAR_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites


class Car : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem

public:
    float velX = -70; //velocidade do bote

    Car();                           // construtor
    ~Car();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Car::Draw() { anim->Draw(x, y, z); }
#endif
