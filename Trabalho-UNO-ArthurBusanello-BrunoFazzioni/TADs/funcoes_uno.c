//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//TADS
#include "funcoes_uno.h"
#include "menu.h"
#include "estruturas_uno.h"
#include "pilha_enc.h"
#include "lista_circ_enc_dupla.h"
#include "lista_enc_dupla.h"


// Fun��o para inicializar um jogador com um ID e uma m�o vazia
Jogador* inicializaJogador(int id){
    Jogador* jogador = (Jogador*)malloc(sizeof(Jogador));
    if(jogador != NULL){
        jogador->id = id;
        jogador->mao = criaListaEnc2(); // Cria uma lista duplamente encadeada vazia para representar a m�o do jogador
    }
    return jogador;
}

// Fun��o para destruir um jogador, liberando a mem�ria alocada para a m�o e para a estrutura do jogador
void destroiJogador(Jogador* jogador){
    if(jogador != NULL){
        destroiListaEnc2(jogador->mao); // Libera a mem�ria alocada para a m�o do jogador
        free(jogador); // Libera a mem�ria alocada para a estrutura do jogador
    }
}

// Fun��o para inicializar o baralho com as cartas do Uno
PilhaEnc* inicializaBaralhoUno(){
    PilhaEnc *baralho = criaPilhaEnc();
    int qntsCartas=0;

    // Iterar sobre os diferentes tipos de cartas (cores)
    for(int cor = AZUL; cor <= VERDE; cor++){
        // Cartas numeradas (de 0 a 9)
        for(int valor = 0; valor <= 9; valor++){
            Carta carta;
            carta.tipo = cor;
            carta.chave = valor;
            for(int i = 0; i < 2; i++){ // Adiciona duas c�pias de cada carta numerada
                empilhaPilhaEnc(baralho, carta);
                qntsCartas++;
            }
        }

        // Cartas especiais (Pular, Reverter, Compra 2)
        for(int i = 0; i < 2; i++){ // Adiciona duas c�pias de cada carta especial
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
            qntsCartas+=3;
        }
    }

    // Cartas coringas (Coringa e Coringa Compra 4)
    for(int i = 0; i < 4; i++){ // Adiciona quatro c�pias de cada carta curinga
        Carta cartaCoringa, cartaCoringaCompra4;
        cartaCoringa.tipo = ESPECIAL;
        cartaCoringaCompra4.tipo = ESPECIAL;
        cartaCoringa.chave = 13; // Coringa
        cartaCoringaCompra4.chave = 14; // Coringa Compra 4
        empilhaPilhaEnc(baralho, cartaCoringa);
        empilhaPilhaEnc(baralho, cartaCoringaCompra4);
        qntsCartas+=2;
    }

    printf("%d cartas no baralho. \n", qntsCartas);

    return baralho;
}

// Funcao compra carta aleat�ria
int compraCarta(PilhaEnc* pilha, ListaEnc2* maoOUmesa) {
    // Verifica se a pilha est� vazia
    if (vaziaPilhaEnc(pilha)) {
        printf("A pilha est� vazia.\n");
        return 0; // Nada a fazer
    }

    // Inicializa o gerador de n�meros aleat�rios
    srand(time(NULL));

    // Obt�m o tamanho atual da pilha
    int tamanhoPilha = 0;
    PilhaEnc *pilhaAux = criaPilhaEnc();
    while (!vaziaPilhaEnc(pilha)) {
        Info carta = desempilhaPilhaEnc(pilha);
        empilhaPilhaEnc(pilhaAux, carta);
        tamanhoPilha++;
    }

    // Gera um n�mero aleat�rio entre 0 e tamanho da pilha - 1
    int posicaoAleatoria = rand() % tamanhoPilha;

    // Desempilha as cartas at� a posi��o aleat�ria
    for (int i = 0; i < posicaoAleatoria; i++) {
        Info carta = desempilhaPilhaEnc(pilhaAux);
        empilhaPilhaEnc(pilha, carta);
    }

    // Carta comprada � a carta na posi��o aleat�ria
    Info cartaComprada = desempilhaPilhaEnc(pilhaAux);

    // Insere a carta comprada na m�o ou na mesa
    insereFimListaEnc2(maoOUmesa, cartaComprada);

    printf("Carta comprada: %d, %s\n", cartaComprada.chave,
           cartaComprada.tipo == AZUL ? "Azul" :
           cartaComprada.tipo == AMARELO ? "Amarelo" :
           cartaComprada.tipo == VERMELHO ? "Vermelho" :
           cartaComprada.tipo == VERDE ? "Verde" : "Especial");
    printf("Carta comprada inserida na m�o.\n");

    // Retorna as cartas restantes � pilha original
    while (!vaziaPilhaEnc(pilhaAux)) {
        Info carta = desempilhaPilhaEnc(pilhaAux);
        empilhaPilhaEnc(pilha, carta);
    }

    // Destroi a pilha auxiliar
    destroiPilhaEnc(pilhaAux);

    return 1;
}


// Funcao que coloca primeira carta na mesa
int primeiraCartaMesa(PilhaEnc* baralho, PilhaEnc* mesa){
    if((vaziaPilhaEnc(mesa) != 1) || (vaziaPilhaEnc(baralho) == 1)) return 0; // Se baralho est� vazio ou mesa tem cartas, retorne 0

    ListaEnc2* listMesa = criaListaEnc2();

    if(compraCarta(baralho, listMesa) == 1){
        if(listMesa->prim->info.chave < 9){ // Se a carta tirada do baralho n�o for nenhuma especial
            empilhaPilhaEnc(mesa, listMesa->prim->info); // Coloca na mesa
        }else{
            primeiraCartaMesa(baralho, mesa); // Sen�o, faz de novo
        }
    }

    return 1;
}

// Funcao que troca a vez dos jogadores na ordem
void trocaOrdemJogadores(ListaCirc2* ordemJogadores){
    ordemJogadores->prim = ordemJogadores->prim->prox;
}

//Funcao que seleciona carta da mao do jogador para jogar na mesa
Carta selecionaCartaMao(Jogador* jogador, PilhaEnc* mesa){
    Carta cartaSelecionada;
    int indiceCarta=-1, tamanhoMao = tamanhoListaEnc2(jogador->mao);
    NodoLEnc2* aux = jogador->mao->prim;

    while(0 > indiceCarta || indiceCarta > tamanhoMao){ // indiceCarta tem que estar dentro do intervalo do tamnho da mao
    printf("Qual carta o jogador %d escolhe? \n", jogador->id);
    scanf("%d", &indiceCarta);
    }

    for(int i=0; i<indiceCarta; i++){ // Alcan�a carta da m�o
        aux = aux->prox;
    }

    //Requisitos para validar carta selecionada
    if(aux->info.tipo == mesa->topo->info.tipo){ //Se for da mesma cor do topo da mesa
        cartaSelecionada = aux->info;
    }
    if(aux->info.chave == mesa->topo->info.chave){ //Se for da mesma chave (n�mero) do topo da mesa
        cartaSelecionada = aux->info;
    }
    if(aux->info.tipo == ESPECIAL || aux->info.chave <= 14){
        cartaSelecionada = aux->info;
    }

    removeNodoListaEnc2(jogador->mao, aux);

    return cartaSelecionada;
}

// Funcao para jogador jogar uma carta na mesa
int jogada(PilhaEnc* baralho, PilhaEnc* mesa, ListaCirc2* ordemJogadores){

    int escolha = -1;
    printf("Jogador &d vai jogar (1) ou comprar (2): \n", ordemJogadores->prim->jogador->id);
    scanf("%d", &escolha);

    if(escolha == 1){ // Se dicidir jogar
        Carta cartaSelecionada = selecionaCartaMao(ordemJogadores->prim->jogador, mesa);
        empilhaPilhaEnc(mesa, cartaSelecionada);
        return 1;
    }
    if(escolha == 2){
        if(compraCarta(baralho, ordemJogadores->prim->jogador->mao) == 1) return 1;
        else return 0;
    }

    return 0;
}
