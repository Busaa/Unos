#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TADS
#include "uno.h"
#include "menu.h"
#include "pilha_enc.h"
#include "fila_enc.h"
#include "lista_circ_enc_dupla.h"
#include "lista_enc_dupla.h"
#include "deque_enc.h"


// Função para inicializar o baralho com as 108 cartas do Uno
PilhaEnc* inicializaBaralhoUno(){
    PilhaEnc *baralho = criaPilhaEnc();

    // Iterar sobre os diferentes tipos de cartas (cores)
    for(int cor = AZUL; cor <= VERDE; cor++){
        // Cartas numeradas (de 0 a 9)
        for(int valor = 0; valor <= 9; valor++){
            Carta carta;
            carta.tipo = cor;
            carta.chave = valor;
            for(int i = 0; i < 2; i++){ // Adiciona duas cópias de cada carta numerada
                empilhaPilhaEnc(baralho, carta);
            }
        }

        // Cartas especiais (Pular, Reverter, Compra 2)
        for(int i = 0; i < 2; i++){ // Adiciona duas cópias de cada carta especial
            Carta cartaPular, cartaReverter, cartaCompra2;
            cartaPular.tipo = cartaReverter.tipo = cartaCompra2.tipo = cor;
            cartaPular.chave = 10; // Pular
            cartaReverter.chave = 11; // Reverter
            cartaCompra2.chave = 12; // Compra 2
            empilhaPilhaEnc(baralho, cartaPular);
            empilhaPilhaEnc(baralho, cartaReverter);
            empilhaPilhaEnc(baralho, cartaCompra2);
        }
    }

    // Cartas curinga (Coringa e Coringa Compra 4)
    for(int i = 0; i < 4; i++){ // Adiciona quatro cópias de cada carta curinga
        Carta cartaCoringa, cartaCoringaCompra4;
        cartaCoringa.tipo = cartaCoringaCompra4.tipo = ESPECIAL;
        cartaCoringa.chave = 14; // Coringa
        cartaCoringaCompra4.chave = 15; // Coringa Compra 4
        empilhaPilhaEnc(baralho, cartaCoringa);
        empilhaPilhaEnc(baralho, cartaCoringaCompra4);
    }

    return baralho;
}

// Funcao que embaralha os elementos de uma pilha
void embaralharPilhaEnc(PilhaEnc *pilha, int numEmbaralhamentos){
    // Verifica se a pilha está vazia ou se tem apenas um elemento
    if(pilha == NULL || pilha->topo == NULL || pilha->topo->prox == NULL) {
        return; // Nada a fazer
    }

    // Crie um array para armazenar os elementos da pilha
    Info *elementos = malloc(sizeof(Info) * numEmbaralhamentos);
    if(elementos == NULL){
        printf("Erro: Falha ao alocar memória para embaralhar os elementos.\n");
        return;
    }

    // Armazene os elementos da pilha no array
    NodoPEnc *aux = pilha->topo;
    int i = 0;
    while(aux != NULL && i < numEmbaralhamentos){
        elementos[i++] = aux->info;
        aux = aux->prox;
    }

    // Embaralhe o array de elementos
    srand(time(NULL)); // Inicializa a semente aleatória
    for(int j = numEmbaralhamentos - 1; j > 0; j--){
        int k = rand() % (j + 1); // Gera um índice aleatório entre 0 e j
        Info temp = elementos[j];
        elementos[j] = elementos[k];
        elementos[k] = temp;
    }

    // Limpe a pilha original
    while(pilha->topo != NULL){
        NodoPEnc *tmp = pilha->topo->prox;
        free(pilha->topo);
        pilha->topo = tmp;
    }

    // Insira os elementos embaralhados de volta na pilha
    for(int l = 0; l < numEmbaralhamentos; l++){
        empilhaPilhaEnc(pilha, elementos[l]);
    }

    // Libere a memória alocada para o array de elementos
    free(elementos);
}
