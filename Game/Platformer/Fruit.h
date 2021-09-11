/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _PLATFORMER_FRUIT_H_
#define _PLATFORMER_FRUIT_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

//enum Gravity { NORMAL, INVERTED };         // tipo da gravidade

// ---------------------------------------------------------------------------------

class Fruit : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    //bool collected = false;
    //uint gravity = NORMAL;              // gravidade atuando sobre o jogador
   // bool keyCtrl = false;               // controle do pressionamento da barra de espaço
   // bool keyCtrlUp = false;               // controle do pressionamento da barra de espaço
    //bool keyCtrlDown = false;               // controle do pressionamento da barra de espaço
   // bool keyCtrlLeft = false;               // controle do pressionamento da barra de espaço
   // bool keyCtrlRight = false;               // controle do pressionamento da barra de espaço

public:
    Fruit(string imageName);                           // construtor
    ~Fruit();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Fruit::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
