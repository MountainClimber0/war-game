#include <stdio.h>
#define TAM_STRING 50
#define MAX_PAISES 5
#include <string.h>
#include "uteis.c"

 typedef struct Territorio
{
    /* list of country names; initialize instances separately */
       char paises [TAM_STRING];
  char corTerritorio [TAM_STRING];
     int numTropas;

} Territorio;


int main() {

 
struct Territorio territorio[MAX_PAISES];

int numPaises = 0;

printf("Bem vindo ao jogo de batalha naval!\n");
printf("Para comecar insira o numero de paises:\n");
scanf("%d", &numPaises);
limparBuffer();

for (int i = 0; i < numPaises ; i++) {
    printf("Insira o nome do pais %d: \n", i+1);
    scanf("%s", territorio[i].paises);

}

printf("seus paises sao:\n");

for(int i = 0; i < numPaises ; i++){

  printf("%d - %s\n", i + 1, territorio[i].paises);


}

return 0;
};