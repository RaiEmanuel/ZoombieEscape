
#include "Engine.h"
#include "frogger.h"
#include "Resources.h"
#include "GameOver.h"
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
    scene = new Scene();

    //bote primeiro para ter prioridade na colisão
    boat = new Boat();
    boat->MoveTo(window->Width() + 45.0f, 310 - 45 - 45 - 45);
    scene->Add(boat, STATIC);
    boat->velX = -50;

    //segundo bote
    boat2 = new Boat();
    boat2->MoveTo(window->Width() + 45.0f, 310 - 45 - 45);
    boat2->velX = -45;
    scene->Add(boat2, STATIC);

    //terceiro bote
    boat3 = new Boat();
    boat3->MoveTo(window->Width() + 45.0f, 310 - 45);
    boat3->velX = -55;
    scene->Add(boat3, STATIC);

    //quarto bote
    boat4 = new Boat();
    boat4->MoveTo(window->Width() + 45.0f, 310);
    boat4->velX = -60;
    scene->Add(boat4, STATIC);

    //fica depois dos botes para preferência na colisão
    backg = new Background("Resources/background.png");
    scene->Add(backg, STATIC);

    /* obs: deletar tudo no destrutor*/

    //maça
    fruit = new Fruit("Resources/apple.png");
    scene->Add(fruit, STATIC);

    //hamburguer
    fruit2 = new Fruit("Resources/hamb.png");
    scene->Add(fruit2, STATIC);
    fruit2->MoveTo(100, 500);

    //hamburguer
    fruit3 = new Fruit("Resources/cabbage.png");
    scene->Add(fruit3, STATIC);
    fruit3->MoveTo(100, 400);

    //hamburguer
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
    car1->MoveTo(window->Width() - 126.0f, 390);
    scene->Add(car1, STATIC);
    car1->velX = -70;


    car2 = new Car();
    car2->MoveTo(window->Width() + 42.0f, 455);
    scene->Add(car2, STATIC);
    car2->velX = -50;

    car3 = new Car();
    car3->MoveTo(window->Width() + 0.0f, 530);
    scene->Add(car3, STATIC);
    car3->velX = -65;

    




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

    /*if (keyCtrlReturn && window->KeyDown(VK_RETURN)) {
        Engine::Next<GameOver>();
        keyCtrlReturn = false;
    }*/
    //if (window->KeyUp(VK_RETURN)) keyCtrlReturn = true;
    //evitar acessar objeto inválido por ter mudado para nova cena (talvez mudar para última posição resolva sem if)
    if (player->statePlayer == LOSE) {
        Engine::Next<GameOver>(player->points);
    }
    else {//PLAYER RUN
        //player ainda jogando
      
        
        if (player->points == 4) {//pegou todas as frutas
            /* OBS: otimizar para evitar essa repetição de carregamento de sprites sempre entrando nesse if*/
            if (keyCtrlTime) {
                t.Start();
                keyCtrlTime = false;
                stateWater = FREEZE;
            }
            if (stateWater == FREEZE) {
                backg->setSprite("Resources/bgfreeze.png");
                backg->activeWater = false;//desativando a possibilidade de morrer em contato com a água
                if (t.Elapsed(1.5f)) {
                    OutputDebugString("==================[ Acabou freeezzzeeeee ]");
                    t.Stop();
                    stateWater = NORMAL;
                }
            }
            else {
                backg->setSprite("Resources/background.png");
                backg->activeWater = true;
            }
            
            
            //fica depois dos botes para preferência na colisão
            //backg = new Background("Resources/bgfreeze.png");
            //scene->Add(backg, STATIC);
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

