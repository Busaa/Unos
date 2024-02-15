#ifndef FUNCOES_UNO
#define FUNCOES_UNO

//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//TADS
#include "menu.h"
#include "estruturas_uno.h"
#include "pilha_enc.h"
#include "lista_circ_enc_dupla.h"
#include "lista_enc_dupla.h"

// Fun��o para inicializar um jogador com um ID e uma m�o vazia
Jogador* inicializaJogador(int id);

// Fun��o para destruir um jogador, liberando a mem�ria alocada para a m�o e para a estrutura do jogador
void destroiJogador(Jogador* jogador);

// Fun��o para inicializar o baralho com as cartas do Uno
PilhaEnc* inicializaBaralhoUno();

// Funcao compra carta aleat�ria
int compraCarta(PilhaEnc* pilha, ListaEnc2* maoOUmesa);

// Funcao que coloca primeira carta na mesa
int primeiraCartaMesa(PilhaEnc* baralho, PilhaEnc* mesa);

// Funcao que troca a vez dos jogadores na ordem
void trocaOrdemJogadores(ListaCirc2* ordemJogadores, int ordem);

//Funcao que seleciona carta da mao do jogador para jogar na mesa
Carta selecionaCartaMao(Jogador* jogador, PilhaEnc* mesa, TipoCarta* corObrigatoria);

// Funcao para jogador jogar uma carta na mesa
int jogada(PilhaEnc* baralho, PilhaEnc* mesa, ListaCirc2* ordemJogadores, TipoCarta* corObrigatoria);

// Funcao carta Pula
void cartaPula(PilhaEnc* mesa, ListaCirc2* ordemJogadores);

// Funcao carta Reverter
void cartaReverter(PilhaEnc* mesa, int* ordem);

// Funcao carta Compra2
void cartaCompra2(PilhaEnc* mesa, ListaCirc2* ordemJogadores, PilhaEnc* baralho);

//Fun��o carta Coringa Escolhe Cor VAI AO FINAL DA JOGADA
void cartaCoringaEscolheCor(PilhaEnc* mesa, TipoCarta* corObrigatoria);

// Fun��o carta Coringa Compra 4
void cartaCoringaCompra4(PilhaEnc* mesa, ListaCirc2* ordemJogadores, TipoCarta* corObrigatoria, PilhaEnc* baralho);

// Verifica Ganhador no final de cada jogada
int verificaGanhador(ListaCirc2* ordemJogadores);

// Fun��o que verifica se jogador s� tem uma carta TODO O FINAL DE JOGADA
void verificaUno(ListaCirc2* ordemJogadores, int* uno);

// Fun��o aplica se o jogador anterior tem s� uma carta TODO O FINAL DE JOGADA
int aplicaUno(ListaCirc2* ordemJogadores, int ordem, int* uno, PilhaEnc* baralho);

#endif
