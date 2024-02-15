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
#include "TADS/jogo.h"

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
    int corObrigatoria = -1; // Valor -1 não é obrigatório jogar uma cor específica, muda com carta coringa
    int uno = 0; //

    // Número de jogadores e número de cartas que cada jogador receberá inicialmente
    int numJogadores = 2;
    int numCartasPorJogador = NUM_MAO_INICIO;

    // Cria e inicializa os jogadores
    ListaCirc2* ordemJogadores = criaListaCirc2();
    Jogador* jogador;
    int ordem = 0; // Marcador de direção da ordem de jogadores
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
    //Inicializando a Mesa
    Mesa* mesa = InicializaMesa(baralho, ordemJogadores, numJogadores); //funcionou

    //Menu Inicialization
    InitAudioDevice();
    Menu* menu = InitMenu();
    //Aduio Inicialization
    Audio* menuMusic = InitAudio("music/rebound sucks - elenne.mp3"); //Menu music
    PlayAudio(menuMusic);
    Audio* menuStart = InitAudio("music/eu-carrego.mp3"); //Menu start
    PlayAudio(menuStart);


    //Textures Inicialization
    Texture2D audioIcon = LoadTexture("textures/audio-icon.png"); //textures do menu
    Texture2D redX = LoadTexture("textures/red-x.png");
    Texture2D background = LoadTexture("textures/escola_br.png");
    Texture2D mesaRabiscada = LoadTexture("textures/mesa_rabiscada.png"); //texturas jogo
    Texture2D cartaCostas = LoadTexture("textures/ben10uno.png");





    // Main game loop
    while (!WindowShouldClose()) //While Esc or leave window(x) arent pressed
    {

        // Desenha o menu de acordo com o valor de loop
        switch (menu->loop) {
            case 0: // Menu principal
                ProcessMenuInput(menu, menuMusic);
                BeginDrawing(); //Drawing
                ClearBackground(RAYWHITE); //limpa a tela pra desenhar
                DrawMenu(menu, menuMusic, audioIcon, redX, background);
                break;
            case 1: // Loop do jogo



                ClearBackground(RAYWHITE);
                DesenhaMesa(mesa, baralho, mesaRabiscada, cartaCostas);

                //volta para o menu
                DrawText("P", 750, 390, 40, YELLOW);
                if(IsKeyPressed(KEY_P)){ //enquanto n voltamos pro menu
                    menu->loop = 0;
                }
                break;
            case 2: // Loop do boss
            // Aqui você colocaria o loop do boss
                break;
            case 3: // Loop do load
            // Aqui você colocaria o loop do load
                break;
            case 4: // Loop da configuração
            // Aqui você colocaria o loop da configuração
                break;
            default:
                menu->loop = 0; //volta pro menu se der ruim
                break;
    }
        EndDrawing(); //End Drawing

    } //Left Game loop

    CloseWindow();  //Close the Windown
    CloseAudioDevice();

    //Freeing memory space
    free(menu);
    UnloadTexture(audioIcon);


    // Libera a memória alocada para o baralho e para os jogadores
    destroiPilhaEnc(baralho);
    for (int i = 0; i < numJogadores; i++) {
        destroiJogador(ordemJogadores->prim->jogador);
    }
    destroiListaCirc2(ordemJogadores);

    return 0;
}

