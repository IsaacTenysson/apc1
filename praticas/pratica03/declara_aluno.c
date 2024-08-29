#include <stdio.h>

int main (){
 int matricula = 24221300;
 short int idade = 21;
 float altura = 1.75f; 
 float peso = 689.50f;
 char sexo = 'M';

  printf("Matricula: %i\n", matricula);
  printf("Idade: %i\n", idade);
  printf("Altura: R$ %.2f m\n", altura);
  printf("Peso:  %.1f KG\n", peso);
  printf("Sexo:  %c\n", sexo);
  return 0;
}