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

} 
Territorio;

int numPaises = 0;


//contador para auxiliar na atribuicao de valores
  int getNumeroPaises(void){
     
scanf("%d", &numPaises);


if (numPaises > MAX_PAISES){

    printf("Numero maximo de paises excedido, o maximo e %d\n", MAX_PAISES);
    return 1;
}else if (numPaises <= 0){
    printf("Numero de paises deve ser maior que 0\n");
    return 1;

}
limparBuffer();
return 0;



}

//loop para atribuir valores as structs
void getPaisesData(Territorio *territorio, int numPaises){
for (int i = 0; i < numPaises ; i++) {

    printf("Insira o nome do pais %d: \n", i+1);
        scanf("%s", territorio[i].paises);

    printf("Insira a cor do pais %d: \n", i+1);
        scanf("%s", territorio[i].corTerritorio);

    printf("Insira o numero de tropas do pais %d: \n", i+1);
        scanf("%d", &territorio[i].numTropas);

     limparBuffer();
    
}
}

// mostrar dados dos paises para o ususario
void displayPaisesData(Territorio *territorio, int numPaises){
printf("Numero de paises: %d\n", numPaises);
printf("seus paises sao:\n");
printf("====================:\n");
//loop para mostrar os valores atribuídos
for(int i = 0; i < numPaises ; i++){
    
printf("%d. %s ( %s, tropas: %d )\n", i+1, territorio[i].paises, territorio[i].corTerritorio , territorio[i].numTropas);
}

}

int turnoAtaque(Territorio *territorio, int numPaises){

int paisAtacante, paisDefensor;


    for(int i = 0; i < numPaises ; i++){
int escolhaAtaque; 
paisAtacante = territorio[i].numTropas;

    
    printf("turno do pais %d\n", i+1);
printf("paises disponiveis para atacar:\n");

for(int j = 0; j < numPaises ; j++){
     if(j != i){
        
        printf("%d. %s\n", j+1, territorio[j].paises);
printf("qual pais voce deseja atacar? (digite o numero correspondente)\n");

     }
}

scanf("%d", &escolhaAtaque);

if (escolhaAtaque < 1 || escolhaAtaque > numPaises || escolhaAtaque == i+1){
    printf("Escolha invalida, tente novamente\n");
    return 1;
}

int forcaAtaque = rand() % paisAtacante + 1;
paisDefensor = territorio[escolhaAtaque - 1].numTropas;
int forcaDefesa = rand() % paisDefensor + 1;

   for(int k = 0; k < numPaises ; k++){
    if(k == escolhaAtaque - 1){
        if (forcaAtaque > forcaDefesa){
            territorio[k].numTropas -= forcaDefesa;
            printf("Ataque bem sucedido! O pais %s perdeu %d tropas\n", territorio[k].paises, forcaDefesa);
            printf("O pais %s tem agora %d tropas\n", territorio[k].paises, territorio[k].numTropas);
                limparBuffer();
        } else {
            territorio[i].numTropas -= forcaAtaque;
            printf("Defesa bem sucedida! O pais %s perdeu %d tropas\n", territorio[i].paises, forcaAtaque);
            printf("O pais %s tem agora %d tropas\n", territorio[i].paises, territorio[i].numTropas);
            limparBuffer();
        }
    }





}




    }


return 0;
}




int main() {

 
Territorio *territorio = malloc( MAX_PAISES * sizeof(Territorio));

if (territorio == NULL) {
    printf("Erro ao alocar memoria\n");
    return 1;
}


printf("Bem vindo ao jogo de batalha naval!\n");
printf("Para comecar insira o numero de paises:\n");

 getNumeroPaises();

getPaisesData(territorio, numPaises);

displayPaisesData(territorio, numPaises);

turnoAtaque(territorio, numPaises);



free(territorio);
return 0;
}

