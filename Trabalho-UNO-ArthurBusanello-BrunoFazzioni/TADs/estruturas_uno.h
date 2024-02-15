#ifndef ESTRUTURAS_UNO
#define ESTRUTURAS_UNO

#define NUM_CARTAS_BARALHO 112
#define NUM_MAO_INICIO 7

typedef enum{
    AZUL,
    AMARELO,
    VERMELHO,
    VERDE,
    ESPECIAL
}TipoCarta;

typedef struct{
   int chave; // 1,2,3,4,5,6,7,8,9, 10 (Pular), 11 (Reverter), 12 (Compra 2), 13 (Coringa), 14 (Coringa Compra 4)
   TipoCarta tipo; // Cor da carta: Azul, Amarelo, Vermelho, Verde, ou Especial
} Carta;

typedef Carta Info;

typedef struct{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct{
   NodoLEnc2 *prim;
}ListaEnc2;

typedef struct{
    int id; //Id do jogador
    ListaEnc2* mao; // Mão do jogador
}Jogador;

typedef struct NodoLCirc2{
   Jogador* jogador;
   struct NodoLCirc2* ant;
   struct NodoLCirc2* prox;
} NodoLCirc2;

#endif
