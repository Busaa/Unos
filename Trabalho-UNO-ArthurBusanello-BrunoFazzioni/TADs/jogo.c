//Arquivo com a implementações das funções do TAD jogo.h
//TAD functions for Menu

//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Tads
#include "funcoes_uno.h"
#include "menu.h"
#include "estruturas_uno.h"
#include "pilha_enc.h"
#include "lista_circ_enc_dupla.h"
#include "lista_enc_dupla.h"
#include "jogo.h"


//Funções
Mesa* InicializaMesa(PilhaEnc* baralho, ListaCirc2* ordemjogadores, int numJogadores) {
    // Aloca memória para a estrutura Mesa jogadores
    Mesa* mesa = (Mesa*)malloc(sizeof(Mesa));
    if (mesa == NULL) {
        printf("Erro ao alocar memória para a mesa.\n");
        return NULL;
    }

    // Inicializa a pilha de cartas na mesa
    mesa->baralho = baralho;

    // Remove a primeira carta do baralho e define como carta atual da mesa
    mesa->cartaAtual = desempilhaPilhaEnc(mesa->baralho);

    // Inicializa o vetor de jogadores
    mesa->numJogadores = numJogadores;
    mesa->ordemJogadores = ordemjogadores;

    // Define o jogador atual como o primeiro jogador
    mesa->jogadorAtual = 0;

    return mesa;
}

//Desenha Mesa
void DesenhaMesa(Mesa* mesa, PilhaEnc* baralho, Texture2D mesaRabiscada, Texture2D cartaCostas) {

    // Desenha o plano de fundo da mesa
    DrawTexture(mesaRabiscada, 0, 0, WHITE);

    // Desenha a carta virada para baixo no meio da mesa
    int metadeX = (GetScreenWidth() - cartaCostas.width) / 2;
    int metadeY = (GetScreenHeight() - cartaCostas.height) / 2;
    DrawTexture(cartaCostas, metadeX - 80, metadeY - 20, WHITE);
}
