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
#include "Brain.h"
#include "Alert.h"

// ------------------------------------------------------------------------------

enum TYPEOBJECT { PLAYER, FRUIT, BOAT, BALL, WATER, ALIEN, CAR, BRAIN, ALERT };


class Frogger : public Game
{
private:
    Player * player = nullptr;      // jogador
    Fruit* fruit = nullptr;      // jogador
    Fruit* fruit2 = nullptr;      // jogador
    Fruit* fruit3 = nullptr;      // jogador
    Fruit* fruit4 = nullptr;      // jogador
    Boat** ppRowBoat1 = nullptr, ** ppRowBoat2 = nullptr,** ppRowBoat3 = nullptr, **ppRowBoat4 = nullptr, ** ppRowBoat5 = nullptr;
    Background * backg = nullptr;
    Alien* alien = nullptr;
    Alien* alien2 = nullptr;
    Car* car1 = nullptr;
    Car* car2 = nullptr;
    Car* car3 = nullptr;
    Brain* brain = nullptr;
    Alert * alertConfused = nullptr;
    Alert* alertFreeze = nullptr;
    bool keyCtrlReturn = false;      // controle do pressionamento do enter
    bool keyCtrlTime = true;               // controle do disparo do relógio. true para disparar relógio, assim ue conseguir os 4 pontos
    bool hitMax = false;    //controla o gamtime evitar vários trabalhos no if
    Timer t; //temporizazdor
    

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif