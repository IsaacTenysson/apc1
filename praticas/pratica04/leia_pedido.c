#include <stdio.h>

int main(){
  char produto[21];
  int quantidade = 0;
  float valor = 0.0f;

  printf("Nome do produto: ");
  scanf("%[^\n]s", produto);
  printf("Insira a quantidade: ");
  scanf("%i", &quantidade);
  printf("Insira o valor: ");
  scanf("%f", &valor);
  printf("===================================\n");
  printf("            P E D I D O\n");
  printf("===================================\n");
  printf("Produto \t Qtd\t Valor Unit\n");
  printf("%-11s  %03i  %8.2f\n", produto, quantidade, valor);
  printf("===================================\n");
  
  return 0;
}