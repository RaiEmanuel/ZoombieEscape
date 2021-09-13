
#ifndef _ALERT_H_
#define _ALERT_H_

// ---------------------------------------------------------------------------------
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"
//#include "Sprite.h"

// ---------------------------------------------------------------------------------
enum STATEALERT {NONE, CONFUSEDCONTROLALERT, FREEZEWATERALERT};
class Alert: public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    
public:
    bool activeWater = true; //se água ativa então ela pode fazer player perder quando em contato
    STATEALERT stateAlert = NONE;

    float velX = 0;
    Alert(string fileName);                       // construtor
    ~Alert();                      // destrutor

    //void setSprite(string fileName);      // atualiza o sprite com nova imagem
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void OnCollision(Object* obj);     // resolução da colisão
};

// ---------------------------------------------------------------------------------
inline void Alert::Draw()
{
    anim->Draw(x, y, z);
}
#endif