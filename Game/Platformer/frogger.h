#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fruit.h"
#include "Boat.h"
#include "Alien.h"
#include "Car.h"

// ------------------------------------------------------------------------------

enum TYPEOBJECT { PLAYER, FRUIT, BOAT, BALL, WATER, ALIEN, CAR };
enum STATEWATER { NORMAL, FREEZE };

class Frogger : public Game
{
private:
    Player * player = nullptr;      // jogador
    Fruit* fruit = nullptr;      // jogador
    Fruit* fruit2 = nullptr;      // jogador
    Fruit* fruit3 = nullptr;      // jogador
    Fruit* fruit4 = nullptr;      // jogador
    Boat* boat = nullptr;
    Boat* boat2 = nullptr;
    Boat* boat3 = nullptr;
    Boat* boat4 = nullptr;
    Background * backg = nullptr;
    Alien* alien = nullptr;
    Alien* alien2 = nullptr;
    Car* car1 = nullptr;
    Car* car2 = nullptr;
    Car* car3 = nullptr;
    bool keyCtrlReturn = false;      // controle do pressionamento da barra de espaço
    bool keyCtrlTime = true;               // controle do disparo do relógio. true para disparar relógio, assim ue conseguir os 4 pontos
    Timer t; //temporizazdor
    STATEWATER stateWater = NORMAL;
public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif