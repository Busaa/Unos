#ifndef _DEQUE_ENC_H_
#define _DEQUE_ENC_H_

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25

typedef struct{
   int chave;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
} Aluno;

typedef Aluno Info;

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

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
