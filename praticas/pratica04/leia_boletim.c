#include <stdio.h>

int main(){
  int matricula = 0;
  float a1 = 0.0f;
  float a2 = 0.0f;
  float media = 0.0f;

  printf("Insira a matricula: ");
  scanf("%i", &matricula);
  printf("Insira a nota A1: ");
  scanf("%f", &a1);
  printf("Insira a nota A2: ");
  scanf("%f", &a2);
  printf("Insira a media: ");
  scanf("%f", &media);
   printf("Matricula \t A1 \t A2 \t Media\n");
  printf("%i \t %.1f \t %.1f \t %.1f\n", matricula, a1, a2, media);
  return 0;
}