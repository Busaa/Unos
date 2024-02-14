//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//TADS
#include "TADs/menu.h"
#include "TADs/estruturas_uno.h"
#include "TADs/funcoes_uno.h"
#include "TADs/pilha_enc.h"
#include "TADs/lista_circ_enc_dupla.h"
#include "TADs/lista_enc_dupla.h"

//Main
int main(void)
{
    //VARIAVEIS
    // Inicializa o baralho
    PilhaEnc* baralho = inicializaBaralhoUno();
    for(int i = 0; i < 2; i++){
        Carta cartaTeste = desempilhaPilhaEnc(baralho);
        printf("%d %d \n", cartaTeste.chave, cartaTeste.tipo);
    }

    // Número de jogadores e número de cartas que cada jogador receberá inicialmente
    int numJogadores = 2;
    int numCartasPorJogador = NUM_MAO_INICIO;

    // Cria e inicializa os jogadores
    ListaCirc2* ordemJogadores = criaListaCirc2();
    Jogador* jogador;
    for(int i = 0; i < numJogadores; i++){
        jogador = inicializaJogador(i + 1); // IDs de jogadores começam em 1
        insereFimListaCirc2(ordemJogadores, jogador);
        printf("Jogador %d na partida! \n", (ordemJogadores->prim)->ant->jogador->id); // Printa o id do ultimo jogador adicionado
    }

    // Distribui cartas para os jogadores
    NodoLCirc2* nodoJogador = ordemJogadores->prim;
    for(int i = 0; i < numJogadores; i++){
        for(int j = 0; j < numCartasPorJogador; j++){
            if(compraCarta(baralho, nodoJogador->jogador->mao) == 1){
                printf("Jogador %d, Carta %d adcionada na mao. \n", nodoJogador->jogador->id, j+1);
            }
        }
        nodoJogador = nodoJogador->prox; // Avança para o próximo jogador na lista circular
    }


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

    // Libera a memória alocada para o baralho e para os jogadores
    destroiPilhaEnc(baralho);
    for (int i = 0; i < numJogadores; i++) {
        destroiJogador(ordemJogadores->prim->jogador);
    }
    destroiListaCirc2(ordemJogadores);

    return 0;
}

