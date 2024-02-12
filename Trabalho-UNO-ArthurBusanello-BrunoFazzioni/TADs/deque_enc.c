#include "deque_enc.h"
#include "uno.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria um deque
DequeEnc* criaDequeEnc(){
   DequeEnc *deque = (DequeEnc*)malloc(sizeof(DequeEnc));
   if (deque != NULL){ // Idealmente, sempre checar!
      deque->ini = NULL;// Representacao de deque vazio
      deque->fim = NULL;
   }
   return deque;
}

// Funcao que destroi um deque
void destroiDequeEnc(DequeEnc *deque){
   NodoLEnc2 *aux = deque->ini;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(deque);
}

// Funcao que insere um elemento no inicio do deque
void insereInicioDequeEnc(DequeEnc *deque, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo != NULL){
      novo->info = info;
      novo->ant = NULL;
      novo->prox = deque->ini;
      if (deque->ini != NULL)
         deque->ini->ant = novo;
      else
         deque->fim = novo;
      deque->ini = novo;
   }
}

// Funcao que insere um elemento no fim do deque
void insereFimDequeEnc(DequeEnc *deque, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo != NULL){
      novo->info = info;
      novo->prox = NULL;
      novo->ant = deque->fim;
      if (deque->fim != NULL)
         deque->fim->prox = novo;
      else
         deque->ini = novo;
      deque->fim = novo;
   }
}

// Funcao que remove um elemento do inicio do deque
Info removeInicioDequeEnc(DequeEnc *deque){
   NodoLEnc2 *aux = deque->ini;
   Info info = aux->info;
   deque->ini = aux->prox;
   if (deque->ini == NULL)
      deque->fim = NULL;
   else
      deque->ini->ant = NULL;
   free(aux);
   return info;
}

// Funcao que remove um elemento do fim do deque
Info removeFimDequeEnc(DequeEnc *deque){
   NodoLEnc2 *aux = deque->fim;
   Info info = aux->info;
   deque->fim = aux->ant;
   if (deque->fim == NULL)
      deque->ini = NULL;
   else
      deque->fim->prox = NULL;
   free(aux);
   return info;
}

// Funcao que determina se um deque eh vazio
int vazioDequeEnc(DequeEnc* deque){
   return (deque->ini == NULL);
}

