
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


    //Menu Inicialization
    InitAudioDevice();
    Menu* menu = InitMenu();
    //Aduio Inicialization
    Audio* menuMusic = InitAudio("music/rebound sucks - elenne.mp3"); //Menu music
    PlayAudio(menuMusic);
    Audio* menuStart = InitAudio("music/eu-carrego.mp3"); //Menu start
    PlayAudio(menuStart);
    //Textures Inicialization
    Texture2D audioIcon = LoadTexture("textures/audio-icon.png");
    Texture2D redX = LoadTexture("textures/red-x.png");

    // Main game loop
    while (!WindowShouldClose()) //While Esc or leave window(x) arent pressed
    {
        ProcessMenuInput(menu, menuMusic);

        BeginDrawing(); //Drawing

            ClearBackground(RAYWHITE);

            DrawMenu(menu, menuMusic, audioIcon, redX); //Menu Drawing



        EndDrawing(); //End Drawing

    } //Left Game loop

    CloseWindow();  //Close the Windown

    //Freeing memory space
    free(menu);
    //I cant free the audio things now and textures too, but the code is more compact with everything on Init Menu/DrawMe
    UnloadTexture(audioIcon);

    return 0;
}

