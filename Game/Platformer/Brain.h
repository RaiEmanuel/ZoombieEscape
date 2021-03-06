/**********************************************************************************
// Player (Arquivo de Cabe?alho)
//
// Cria??o:     20 Abr 2012
// Atualiza??o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _PLATFORMER_BRAIN_H_
#define _PLATFORMER_BRAIN_H_

// ---------------------------------------------------------------------------------
// Inclus?es

#include "Types.h"                      // tipos espec?ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima??o de sprites

// ------------------------------------------------------------------------------

//enum Gravity { NORMAL, INVERTED };         // tipo da gravidade

// ---------------------------------------------------------------------------------

class Brain : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima??o do personagem
    //uint gravity = NORMAL;              // gravidade atuando sobre o jogador
   // bool keyCtrl = false;               // controle do pressionamento da barra de espa?o
   // bool keyCtrlUp = false;               // controle do pressionamento da barra de espa?o
    //bool keyCtrlDown = false;               // controle do pressionamento da barra de espa?o
   // bool keyCtrlLeft = false;               // controle do pressionamento da barra de espa?o
   // bool keyCtrlRight = false;               // controle do pressionamento da barra de espa?o

public:
    float velX = -70; //velocidade do bote

    Brain();                           // construtor
    ~Brain();                          // destrutor

    void OnCollision(Object* obj);     // resolu??o da colis?o
    void Update();                      // atualiza??o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun??o Membro Inline

inline void Brain::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
