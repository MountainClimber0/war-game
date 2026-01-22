#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
#define TAM_STRING 50
#define MAX_PAISES 5

#include "uteis.c"
//definicao da struct territorio
 typedef struct Territorio
{
    /* list of country names; initialize instances separately */
       char paises [TAM_STRING];
  char corTerritorio [TAM_STRING];
     int numTropas;

} Territorio;


int main() {

 
Territorio *territorio = malloc( MAX_PAISES * sizeof(Territorio));

if (territorio == NULL) {
    printf("Erro ao alocar memoria\n");
    return 1;
}


 
//contador para auxiliar na atribuicao de valores
int numPaises = 0;

printf("Bem vindo ao jogo de batalha naval!\n");
printf("Para comecar insira o numero de paises:\n");
scanf("%d", &numPaises);
limparBuffer();


//loop para atribuir valores as structs
for (int i = 0; i < numPaises ; i++) {

    printf("Insira o nome do pais %d: \n", i+1);
        scanf("%s", territorio[i].paises);

    printf("Insira a cor do pais %d: \n", i+1);
        scanf("%s", territorio[i].corTerritorio);

    printf("Insira o numero de tropas do pais %d: \n", i+1);
        scanf("%d", &territorio[i].numTropas);

     limparBuffer();
     
}

printf("seus paises sao:\n");
printf("====================:\n");
//loop para mostrar os valores atribuídos
for(int i = 0; i < numPaises ; i++){

printf("%s\n", territorio[i].paises);
printf("cor : %s\n", territorio[i].corTerritorio);
printf("com %d tropas\n", territorio[i].numTropas);
printf("====================\n");
}
free(territorio);

return 0;
}; 