
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "GameOver.h"
#include "Win.h"
#include "SplashScreen.h"

// -----------------------------------------------------------------------------

Scene* Frogger::scene = nullptr;

// -----------------------------------------------------------------------------

void Frogger::Init()
{
    /* XXXXXXXXXXXXXXXXXXXXXXXXXXXX */
    /*  Deletar tudo no fim          */
    /* XXXXXXXXXXXXXXXXXXXXXXXXXXXX */
    // cria cena do jogo
    /* obs: deletar tudo no destrutor*/
    scene = new Scene();

    alertConfused = new Alert("Resources/alerts.png");
    scene->Add(alertConfused, STATIC);
    //alertConfused->MoveTo(100, 200);

    alertFreeze = new Alert("Resources/alerts.png");
    scene->Add(alertFreeze, STATIC);
    //alertFreeze->MoveTo(250,200);
    alertFreeze->Translate(105, 0);
    //bote primeiro para ter prioridade na colisão
    
    /* ESTRATÉGIA PARA CONTORNAR O DELETE X EM VEZ DO DELETE [] X NA DELEÇÃO DA CENA; */
    ppRowBoat1 = new Boat * [3];//cria 3 ponteiros referente a 3 barcos
    ppRowBoat2 = new Boat * [3];//cria 3 ponteiros referente a 3 barcos
    ppRowBoat3 = new Boat * [3];//cria 3 ponteiros referente a 3 barcos
    ppRowBoat4 = new Boat * [3];//cria 3 ponteiros referente a 3 barcos
    /* OBSSS: DELETAR PONTEIRO DE PONTEIROO. PONTEIROS SIMPLES A CENA SE ENCARREGADE DE DELETAR */
    //90 é altura máxima da água
    //20 é altura do bote
    //12 é o espaço vazia de margem entre botes
    for (uint i = 0; i < 3; ++i) {
        /* 111111111111111111 */
        /* Alocação da primeira linha*/
        ppRowBoat1[i] = new Boat();
        ppRowBoat1[i]->MoveTo(window->Width() + 300.0f * i, 90 + 12 + 20);
        ppRowBoat1[i]->velX = -120;
        scene->Add(ppRowBoat1[i], STATIC);
        float heightBoat1 = 90 + 12 + 40 + 12;
        /* 222222222222222222 */
        /* Alocação da segunda  linha*/
        ppRowBoat2[i] = new Boat();
        ppRowBoat2[i]->MoveTo(window->Width() + 300.0f * i + 50, heightBoat1 + 12 + 20);
        ppRowBoat2[i]->velX = -80;
        scene->Add(ppRowBoat2[i], STATIC);
        float heightBoat2 = heightBoat1 + 12 + 40 + 12; 
        /* 3333333333333333333 */
        /* Alocação da terceira  linha*/
        ppRowBoat3[i] = new Boat();
        ppRowBoat3[i]->MoveTo(window->Width() + 300.0f * i + 100, heightBoat2 + 12 + 20);
        ppRowBoat3[i]->velX = -100;
        scene->Add(ppRowBoat3[i], STATIC);
        float heightBoat3 = heightBoat2 + 12 + 40 + 12; 
        /* 4444444444444444444 */
        /* Alocação da terceira  linha*/
        ppRowBoat4[i] = new Boat();
        ppRowBoat4[i]->MoveTo(window->Width() + 300.0f * i + 50, heightBoat3 + 12 + 20);
        scene->Add(ppRowBoat4[i], STATIC);
        ppRowBoat4[i]->velX = -90;
      
    }
    
    /* BACKGROUND -----------------------------*/

    //fica depois dos botes para preferência na colisão
    backg = new Background("Resources/background.png");
    scene->Add(backg, STATIC);

    //maça
    fruit = new Fruit("Resources/apple.png");
    scene->Add(fruit, STATIC);

    //hamburguer
    fruit2 = new Fruit("Resources/hamb.png");
    scene->Add(fruit2, STATIC);
    fruit2->MoveTo(100, 500);

    //cabbage
    fruit3 = new Fruit("Resources/cabbage.png");
    scene->Add(fruit3, STATIC);
    fruit3->MoveTo(100, 400);
    

    //watermellon
    fruit4 = new Fruit("Resources/watermellon.png");
    scene->Add(fruit4, STATIC);
    fruit4->MoveTo(300, 400);

    player = new Player();
    scene->Add(player, MOVING);

    alien = new Alien(250);
    scene->Add(alien, STATIC);
    alien2 = new Alien(200);
    scene->Add(alien2, STATIC);

    //bote primeiro para ter prioridade na colisão
    car1 = new Car();
    car1->MoveTo(window->Width() + 200, 390);
    scene->Add(car1, STATIC);
    car1->velX = -130;

    car2 = new Car();
    car2->MoveTo(window->Width() + 300, 455);
    scene->Add(car2, STATIC);
    car2->velX = -100;

    car3 = new Car();
    car3->MoveTo(window->Width(), 530);
    scene->Add(car3, STATIC);
    car3->velX = -110;

    brain = new Brain();
    brain->MoveTo(window->Width()/2.0f, 42);
    scene->Add(brain, STATIC);
}

// ------------------------------------------------------------------------------

void Frogger::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->CollisionDetection();
    // atualiza cena do jogo
    scene->Update();
    if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        keyCtrlReturn = false;
        Engine::Next<Win>(player->points);
        return;
    }
    if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
    //evitar acessar objeto inválido por ter mudado para nova cena (talvez mudar para última posição resolva sem if)
    if (player->statePlayer == LOSE) {
        Engine::Next<GameOver>(player->points);
        //Engine::Next<Win>(player->points);
    }
    else {//PLAYER RUN ou CONFUSED
        //player ainda jogando
        if (player->statePlayer == WIN)
            Engine::Next<Win>(player->points);
        else
        {
            //RUN OU CONFUSED
            if (player->statePlayer == CONFUSED) { //configura alerta
                alertConfused->stateAlert = CONFUSEDCONTROLALERT;
            }
            if (player->points == 4) {//pegou todas as frutas
                if (keyCtrlTime) {
                    t.Start();
                    keyCtrlTime = false;//não há mais disparos do temporizador
                    backg->stateWater = FREEZE;
                    backg->activeWater = false;
                    backg->setSprite("Resources/backgroundfreeze.png");

                    //configura alerta
                    alertFreeze->stateAlert = FREEZEWATERALERT;

                }
                else {
                    if (t.Elapsed(1.5f)) {
                        OutputDebugString("==================[ Acabou freeezzzeeeee ]");
                        t.Reset();
                        t.Stop();
                        backg->stateWater = NORMAL;
                        backg->activeWater = true;
                        backg->setSprite("Resources/background.png");
                        alertFreeze->stateAlert = NONE;
                    }
                }
            }
        }
    }
}

// ------------------------------------------------------------------------------

void Frogger::Draw()
{
    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Frogger::Finalize()
{
    delete scene;
    delete[] ppRowBoat1;
    delete[] ppRowBoat2;
    delete[] ppRowBoat3;
    delete[] ppRowBoat4;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(704,632);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Frogger");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new SplashScreen());
    //int status = engine->Start(new GameOver());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

