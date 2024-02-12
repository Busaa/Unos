
//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TADS
#include "TADs/menu.h"
#include "TADs/uno.h"
#include "TADs/pilha_enc.h"
#include "TADs/fila_enc.h"
#include "TADs/lista_circ_enc_dupla.h"
#include "TADs/lista_enc_dupla.h"
#include "TADs/deque_enc.h"


//Main
int main(void)
{
    // Iniciando variáveis
    PilhaEnc* baralho = criaPilhaEnc();
    PilhaEnc* mesa = criaPilhaEnc();
    ListaCirc2* ordemJogadores = criaListaCirc2();
    ListaEnc2* mao = criaListaEnc2();


    //Screen Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "UNOs");
    SetTargetFPS(60);

    //Menu Inicialization
    Menu* menu = InitMenu();
    InitAudioDevice(); //Audio ligado
    Audio* menuMusic = InitAudio("music/rebound sucks - elenne.mp3"); //Menu music
    PlayAudio(menuMusic);
    Audio* menuStart = InitAudio("music/eu-carrego.mp3"); //Menu start
    PlayAudio(menuStart);

    // Main game loop
    while (!WindowShouldClose()) //While Esc or leave window(x) arent pressed
    {
        ProcessMenuInput(menu);

        BeginDrawing(); //Drawing

            ClearBackground(RAYWHITE);

            DrawMenu(menu); //Menu Drawing



        EndDrawing(); //End Drawing

    } //Left Game loop

    CloseWindow();  //Close the Windown

    //Freeing memory space
    free(menu);

    return 0;
}

