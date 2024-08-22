#include <stdio.h>

int main(){
  printf("===================================\n");
  printf("%25s\n","NOTA LEGAL");
  printf("===================================\n");
  printf("%-11s \t %s \t %s  \n", "Produto", "Qtd", "Valor Unit");
  printf("%-11s \t %03i \t %10.2f \n","Camiseta", 2, 39.99);
  printf("%-11s \t %03i \t %10.2f \n","Calca", 1, 89.90);
  printf("%-11s \t %03i \t %10.2f \n", "Meia Social", 3, 19.99);
  printf("===================================\n");
  printf("%-11s \t  \t \t %10.2f\n", "Total", 229.85);
  return 0;
}