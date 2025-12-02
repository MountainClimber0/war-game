#include <stdio.h>
#define TAM_STRING 50

 typedef struct Territorio
{
    /* list of country names; initialize instances separately */
       char paises [TAM_STRING];
  char corTerritorio [TAM_STRING];
     int numTropas;
    int numPaises;
} Territorio;
int main() {
    Territorio territorios;
printf("insira o numero de paises:\n");
scanf("%d", &territorios.numPaises);
for (int i = 0; i < territorios.numPaises; i++) {
    
    printf("Insira o nome do pais %d: \n", i);
    scanf("%s", &territorios.paises[i+1]);
    
    
}

return 0;
};