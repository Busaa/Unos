#include "lista_circ_enc_dupla.h"
#include "uno.h"
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
   NodoLEnc2 *aux = lista->prim->prox;
   while(aux != lista->prim){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCirc2(ListaCirc2 *lista){
   NodoLEnc2* aux = lista->prim;
   printf("-----------------------------------------\n");
    printf("%d | %d \n", aux->info.chave,
                               aux->info.tipo);

   for(aux = lista->prim->prox; aux != lista->prim; aux = aux->prox)
      printf("%d | %d \n", aux->info.chave,
                               aux->info.tipo);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaCirc2(ListaCirc2* lista, int chave){
   NodoLEnc2 *aux;
   if (lista->prim->info.chave == chave)
         return lista->prim;

   for(aux = lista->prim->prox; aux != lista->prim; aux = aux->prox)
      if (aux->info.chave == chave)
         return aux;
   return NULL;
}

int insereFimListaCirc2(ListaCirc2 *lista, Info info) {
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL)
      return 0;

   novo->info = info;

   if (lista->prim == NULL) {
      novo->ant = novo;
      novo->prox = novo;
   } else {
      novo->ant = lista->prim->ant;
      novo->prox = lista->prim;
      (lista->prim->ant)->prox = novo;
      lista->prim->ant = novo;
   }
   return 0;
}

int removeInfoListaCirc2(ListaCirc2* lista, int chave) {
   NodoLEnc2 *aux = lista->prim;
   while (aux != NULL && aux->info.chave != chave) {
      aux = aux->prox;
   }
   if (aux != NULL) {
      if (aux->ant == NULL) {
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;
      } else {
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
      }
      free(aux);
      return 1;
   }
   return 0; // Não encontrou
}

