#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

#include "estruturas_uno.h"

// ESTRUTURA NodoLEnc2 e ListaEnc2 ESTÃO NO TAD estruturas_uno.h


// Funcao que cria uma lista
ListaEnc2* criaListaEnc2();

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc2(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc2(ListaEnc2 *lista, Info info);

// Funcao que insere um nodo no fim de uma lista
int insereFimListaEnc2(ListaEnc2 *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaEnc2(ListaEnc2* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc2(ListaEnc2* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeNodoListaEnc2(ListaEnc2* lista, NodoLEnc2* nodo);

// Funcao que conta o tamanho de uma lista
int tamanhoListaEnc2(ListaEnc2* lista);

#endif
