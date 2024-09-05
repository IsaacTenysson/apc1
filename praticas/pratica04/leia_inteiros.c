#include <stdio.h>

int main(){
  int numero = 0;
  int coord_x = 0;
  int coord_y = 0;
  
  printf("Digite um número inteiro: ");
  scanf("%i", &numero);
  
  printf("Você digitou: %i\n", numero);

  printf("Digite a coordenada x: ");   
  scanf("%i", &coord_x);
  printf("Digite a coordenada y: ");
  scanf("%i", &coord_y);
  printf("Você digitou: %i e %i\n", coord_x, coord_y);
  return 0;
}