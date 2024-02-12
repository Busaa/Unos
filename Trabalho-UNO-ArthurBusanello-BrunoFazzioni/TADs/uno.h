#ifndef UNO
#define UNO

#define NUM_CARTAS_BARALHO 108

typedef enum{
    AZUL,
    AMARELO,
    VERMELHO,
    VERDE,
    ESPECIAL
}TipoCarta;

typedef struct{
   int chave; // 1,2,3,4,5,6,7,8,9, 10 (Pular), 11 (Reverter), 12 (Compra 2), 14 (Coringa), 15 (Coringa Compra 4)
   TipoCarta tipo; // Cor da carta: Azul, Amarelo, Vermelho, Verde, ou Especial
} Carta;

typedef Carta Info;

typedef struct{
    int id; //Id do jogador
    Carta mao[NUM_CARTAS_BARALHO]; // Mão do jogador PRECISA MUDAR PARA LISTA DUPLAMENTE ENCADEADA
}Jogador;

typedef struct{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

/*typedef struct{
    PilhaEnc baralho;
} Baralho;

typedef struct{
    PilhaEnc mesa;
} Mesa;

typedef struct{
    ListaCirc2 ordem_jogadores;
} Ordem;
*/

#endif
