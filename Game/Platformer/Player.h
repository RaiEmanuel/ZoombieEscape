#ifndef _PLATFORMER_PLAYER_H_
#define _PLATFORMER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Boat.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum StatePlayer{ RUN, LOSE, CONFUSED };         // estado do jogador, jogando ou perdeu e chama gameover
enum StateDirectionPlayer {LEFT, RIGHT, UP, DOWN};
// ---------------------------------------------------------------------------------

class Player : public Object
{
    
private:
    TileSet * tileset = nullptr;        // folha de sprites do personagem
    Animation * anim = nullptr;         // animação do personagem
    bool keyCtrl = false;               // controle do pressionamento da barra de espaço
    bool keyCtrlUp = false;               // controle do pressionamento da barra de espaço
    bool keyCtrlDown = false;               // controle do pressionamento da barra de espaço
    bool keyCtrlLeft = false;               // controle do pressionamento da barra de espaço
    bool keyCtrlRight = false;               // controle do pressionamento da barra de espaço
    bool keyCtrlReturn = false;               // controle do pressionamento da barra de espaço
    StateDirectionPlayer stateDirectionPlayer = UP;
    int velX = 2000;
    int velY = 2000;

public:
    
    uint points = 0;
    Boat* boat = nullptr;                  //bote diferente de nulo quando colidindo com um. saiu do bote zera. isso serve para pode andar ambos juntos
    StatePlayer statePlayer = RUN;
    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif