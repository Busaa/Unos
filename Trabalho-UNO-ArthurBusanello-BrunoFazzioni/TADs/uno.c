#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para usar a função time() para embaralhar pilha

//TADS
#include "uno.h"
#include "menu.h"
#include "pilha_enc.h"
#include "fila_enc.h"
#include "lista_enc_dupla.h"
#include "deque_enc.h"


// Função para inicializar o baralho com as cartas do Uno
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
            cartaPular.tipo = cor;
            cartaReverter.tipo = cor;
            cartaCompra2.tipo = cor;
            cartaPular.chave = 10; // Pular
            cartaReverter.chave = 11; // Reverter
            cartaCompra2.chave = 12; // Compra 2
            empilhaPilhaEnc(baralho, cartaPular);
            empilhaPilhaEnc(baralho, cartaReverter);
            empilhaPilhaEnc(baralho, cartaCompra2);
        }
    }

    // Cartas coringas (Coringa e Coringa Compra 4)
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

int embaralharPilhaEnc(PilhaEnc *pilha, int numEmbaralhamentos){
    // Verificar se a pilha foi corretamente inicializada
    if(pilha == NULL || pilha->topo == NULL || pilha->topo->prox == NULL){
        printf("Erro: Pilha não inicializada ou vazia.\n");
        return 0; // Nada a fazer
    }

    // Criar uma lista duplamente encadeada auxiliar para armazenar os elementos da pilha
    ListaEnc2 *listaAuxiliar = criaListaEnc2();
    if(listaAuxiliar == NULL){
        printf("Erro: Falha ao alocar memória para lista auxiliar.\n");
        return 0;
    }

    // Transfir os elementos da pilha para a lista duplamente encadeada
    while(!vaziaPilhaEnc(pilha)){
        Info carta = desempilhaPilhaEnc(pilha);
        if(!insereInicioListaEnc2(listaAuxiliar,carta)){
            printf("Erro: Falha ao inserir elemento na lista auxiliar.\n");
            destroiListaEnc2(listaAuxiliar); // Liberar memória antes de retornar
            return 0;
        }
    }

    // Embaralhando a lista auxiliar (os elementos já estão na ordem inversa da pilha)
    for(int i = 0; i < numEmbaralhamentos; i++){
        // Verificar se a lista auxiliar não está vazia
        if(listaAuxiliar->prim == NULL){
            printf("Erro: Lista auxiliar vazia.\n");
            destroiListaEnc2(listaAuxiliar); // Liberar memória antes de retornar
            return 0;
        }

        // Percorrer a lista até um ponto aleatório
        int tamanhoLista = tamanhoListaEnc2(listaAuxiliar);
        int posicaoAleatoria = rand() % tamanhoLista;
        NodoLEnc2 *aux = listaAuxiliar->prim;

        for(int j = 0; j < posicaoAleatoria; j++){
            if(aux == NULL){
                printf("Erro: Acesso indevido à memória.\n");
                destroiListaEnc2(listaAuxiliar); // Liberar memória antes de retornar
                return 0;
            }
            aux = aux->prox;
        }

        // Removendo o nodo da lista auxiliar
        if(aux->ant != NULL){
            (aux->ant)->prox = aux->prox; // Conecta o nodo anterior ao nodo seguinte do nodo corrente
        }else{
            listaAuxiliar->prim = aux->prox; // Coloca nodo seguinte no inicio
        }
        if(aux->prox != NULL){
            (aux->prox)->ant = aux->ant; //
        }

        // Insira o nodo na pilha
        empilhaPilhaEnc(pilha, aux->info);

        // Libere a memória alocada para o nodo
        free(aux);
    }

    // Destrua a lista auxiliar
    destroiListaEnc2(listaAuxiliar);

    return 1;
}
