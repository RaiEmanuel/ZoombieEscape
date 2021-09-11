#ifndef _ALIEN_H_
#define _ALIEN_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

class Alien : public Object
{

private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    int velY = 1;

public:
   
   
    Alien(int velYAlien);                           // construtor
    ~Alien();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Alien::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
