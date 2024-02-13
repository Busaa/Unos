#ifndef _LISTA_CIRC_ENC_DUPLA_H_
#define _LISTA_CIRC_ENC_DUPLA_H_

#include "uno.h"

// ESTRUTURA NodoLEnc2 ESTÁ NO TAD uno.h

typedef struct{
   NodoLEnc2 *prim;
} ListaCirc2;

// Funcao que cria uma lista
ListaCirc2* criaListaCirc2();

// Funcao que destroi uma lista
void destroiListaCirc2(ListaCirc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCirc2(ListaCirc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaCirc2(ListaCirc2 *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaCirc2(ListaCirc2* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaCirc2(ListaCirc2* lista, int chave);

#endif
