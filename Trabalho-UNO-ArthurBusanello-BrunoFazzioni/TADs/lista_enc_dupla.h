#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

#include "uno.h"

// ESTRUTURA NodoLEnc2 ESTÁ NO TAD uno.h

typedef struct{
   NodoLEnc2 *prim;
}ListaEnc2;

typedef struct{
    int id; //Id do jogador
    ListaEnc2* mao; // Mão do jogador PRECISA MUDAR PARA LISTA DUPLAMENTE ENCADEADA
}Jogador;

// Funcao que cria uma lista
ListaEnc2* criaListaEnc2();

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc2(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereFimListaEnc2(ListaEnc2 *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaEnc2(ListaEnc2* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc2(ListaEnc2* lista, int chave);

#endif
