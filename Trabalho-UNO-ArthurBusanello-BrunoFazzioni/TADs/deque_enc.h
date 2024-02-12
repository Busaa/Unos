#ifndef _DEQUE_ENC_H_
#define _DEQUE_ENC_H_

#include "uno.h"

struct NodoLEnc2{
   Info info;
   struct NodoLEnc2 *ant;
   struct NodoLEnc2 *prox;
};

typedef struct dequeEnc{
   NodoLEnc2 *ini;
   NodoLEnc2 *fim;
} DequeEnc;

// Funcao que cria um deque
DequeEnc* criaDequeEnc();

// Funcao que destroi um deque
void destroiDequeEnc(DequeEnc *deque);

// Funcao que insere um elemento no inicio do deque
void insereInicioDequeEnc(DequeEnc *deque, Info info);

// Funcao que insere um elemento no fim do deque
void insereFimDequeEnc(DequeEnc *deque, Info info);

// Funcao que remove um elemento do inicio do deque
Info removeInicioDequeEnc(DequeEnc *deque);

// Funcao que remove um elemento do fim do deque
Info removeFimDequeEnc(DequeEnc *deque);

// Funcao que determina se um deque eh vazio
int vazioDequeEnc(DequeEnc* deque);


#endif
