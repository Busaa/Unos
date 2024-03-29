#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaListaEnc2(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   if(lista != NULL) // Idealmente, sempre checar!
      lista->prim = NULL; // Representacao de lista vazia
   return lista;
}

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc2(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %s)\n", aux->info.chave,
                               aux->info.tipo);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaEnc2(ListaEnc2* lista, int chave){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.chave == chave)
         return aux;
   return NULL;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc2(ListaEnc2 *lista, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL) // Idealmente, sempre checar!
      return 0;
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que insere um nodo no fim de uma lista
int insereFimListaEnc2(ListaEnc2 *lista, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL) // Idealmente, sempre checar!
      return 0;
   novo->info = info;
   novo->prox = NULL;

   if (lista->prim == NULL) { // Se a lista estiver vazia
      novo->ant = NULL;
      lista->prim = novo;
   } else { // Se a lista n�o estiver vazia
      NodoLEnc2 *aux = lista->prim;
      while (aux->prox != NULL) { // Encontra o �ltimo nodo
         aux = aux->prox;
      }
      novo->ant = aux;
      aux->prox = novo;
   }
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc2(ListaEnc2* lista, int chave){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL && aux->info.chave != chave){
      aux = aux->prox;
   }
   if (aux != NULL){
      if (aux->ant == NULL){
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;
      }else{
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
      }
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeNodoListaEnc2(ListaEnc2* lista, NodoLEnc2* nodo){
    if (nodo == NULL) {
        return 0; // Nodo inv�lido
    }

    if (nodo->ant == NULL) {
        lista->prim = nodo->prox;
        if (nodo->prox != NULL) {
            nodo->prox->ant = NULL;
        }
    } else {
        nodo->ant->prox = nodo->prox;
        if (nodo->prox != NULL) {
            nodo->prox->ant = nodo->ant;
        }
    }
    free(nodo);
    return 1;
}


// Funcao que conta o tamanho de uma lista
int tamanhoListaEnc2(ListaEnc2* lista){
    NodoLEnc2* aux = lista->prim;
    int tamanho = 0;

    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}
