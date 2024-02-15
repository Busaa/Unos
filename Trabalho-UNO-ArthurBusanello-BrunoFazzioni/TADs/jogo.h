//Implementação do TAD para o MENU menu.h
//TAD Menu

#ifndef JOGO_H
#define JOGO_H


//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//TADS meu
//TADS
#include "funcoes_uno.h"
#include "menu.h"
#include "estruturas_uno.h"
#include "pilha_enc.h"
#include "lista_circ_enc_dupla.h"
#include "lista_enc_dupla.h"


//Estruturas
typedef struct Mesa{ 
    PilhaEnc* baralho; //baralho de compra na mesa
    Carta cartaAtual; //Carta atualmente na mesa
    ListaCirc2* ordemJogadores; //Vetor de jogadores jogando
    int numJogadores; 
    int jogadorAtual; //jogador que atualmetne está com o turno
}Mesa;

//Funções
Mesa* InicializaMesa(PilhaEnc* baralho, ListaCirc2* ordemjogadores, int numJogadores);
void DesenhaMesa(Mesa* mesaJogo, PilhaEnc* baralho, Texture2D mesaRabiscada, Texture2D cartaCostas);

#endif // MENU_H end