#include <stdio.h>
#include <string.h>
#include "deque_enc.h"

int main(){

   DequeEnc *deque;
   deque = criaDequeEnc();
   
   // Aqui seriam chamadas as funcoes de inicializacao de nodos
   Info info1 = {1, "Fulano de Tal", "fulano@email.com"};
   Info info2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   Info info3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   Info info4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   Info info5 = {5, "Ciclano de Tal", "ciclano@email.com"};
    
   insereInicioDequeEnc(deque, info1); 
   insereFimDequeEnc(deque, info2); 
   insereInicioDequeEnc(deque, info3); 
   insereFimDequeEnc(deque, info4); 
   insereInicioDequeEnc(deque, info5); 
   
   Info infoAux;
   while (!vazioDequeEnc(deque)){
      infoAux = removeInicioDequeEnc(deque);
      printf("%d | %s (%s)\n", infoAux.chave, infoAux.nome, infoAux.email);   
   }

   destroiDequeEnc(deque);

   return 0;
}
