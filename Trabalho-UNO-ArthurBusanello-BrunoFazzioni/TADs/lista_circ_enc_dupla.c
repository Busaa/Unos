#include "lista_circ_enc_dupla.h"
#include "estruturas_uno.h"
#include "funcoes_uno.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista circular
ListaCirc2* criaListaCirc2(){
   ListaCirc2 *lista = (ListaCirc2*)malloc(sizeof(ListaCirc2));
   if (lista != NULL) // Idealmente, sempre checar!
      lista->prim = NULL; // Representacao de lista vazia
   return lista;
}

// Funcao que destroi uma lista circular
void destroiListaCirc2(ListaCirc2 *lista){
   NodoLCirc2 *aux = lista->prim->prox;
   while(aux != lista->prim){
       NodoLCirc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCirc2(ListaCirc2 *lista){
   NodoLCirc2* aux = lista->prim;
   printf("-----------------------------------------\n");
    printf("%d | %d \n", aux->jogador->id,
                               aux->jogador->mao->prim->info.chave);

   for(aux = lista->prim->prox; aux != lista->prim; aux = aux->prox)
      printf("%d | %d \n", aux->jogador->id,
                               aux->jogador->mao->prim->info.chave);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLCirc2* buscaInfoListaCirc2(ListaCirc2* lista, int idJogador){
   NodoLCirc2 *aux;
   if(lista->prim->jogador->id == idJogador)
         return lista->prim;

   for(aux = lista->prim->prox; aux != lista->prim; aux = aux->prox)
      if (aux->jogador->id == idJogador)
         return aux;
   return NULL;
}

int insereFimListaCirc2(ListaCirc2 *lista, Jogador* jogador) {
   NodoLCirc2 *novo = (NodoLCirc2*)malloc(sizeof(NodoLCirc2));
   if (novo == NULL)
      return 0;

   novo->jogador = jogador;

   if(lista->prim == NULL){ //Se lista ta vazia
       lista->prim = novo; // Novo nodo é p primeiro da lista
      novo->ant = novo; // Ponteiro ant aponta para o proprio nodo
      novo->prox = novo; // Ponteiro prox aponta para o proprio nodo
   } else {
      novo->ant = lista->prim->ant; // Ponteiro ant aponta para o anterior do lista->prim
      novo->prox = lista->prim;  // Ponteiro prox aponta para o lista->prim
      (lista->prim->ant)->prox = novo; // Ponteiro prox do ultimo nodo aponta para o novo nodo
      (lista->prim)->ant = novo; // Ponteiro ant do lista->prim aponta para o novo nodo
   }
   return 1; // Nodo é adicionado no fim da lista
}

int removeInfoListaCirc2(ListaCirc2* lista, int idJogador) {
   NodoLCirc2 *aux = lista->prim;
   while(aux != NULL && aux->jogador->id != idJogador) {
      aux = aux->prox;
   }
   if(aux != NULL){
      if(aux->ant == NULL){
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
   return 0; // Não encontrou
}

