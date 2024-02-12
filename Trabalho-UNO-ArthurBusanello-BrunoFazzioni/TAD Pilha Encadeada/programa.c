#include <stdio.h>
#include <string.h>
#include "pilha_enc.h"

int main(){

   PilhaEnc *pilha;
   pilha = criaPilhaEnc();
   
   // Aqui seriam chamadas as funcoes de inicializacao de nodos
   Info info1 = {1, "Fulano de Tal", "fulano@email.com"};
   Info info2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   Info info3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   Info info4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   Info info5 = {5, "Ciclano de Tal", "ciclano@email.com"};
     
   empilhaPilhaEnc(pilha, info1); 
   empilhaPilhaEnc(pilha, info2); 
   empilhaPilhaEnc(pilha, info3); 
   empilhaPilhaEnc(pilha, info4); 
   empilhaPilhaEnc(pilha, info5); 
   
   Info infoAux;
   while (!vaziaPilhaEnc(pilha)){
      infoAux = desempilhaPilhaEnc(pilha);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);   
   }
   
   destroiPilhaEnc(pilha);

   return 0;
}
