# include <stdio.h>

int main(){

  int a = 1;
  int b = 0;
  int c = 1;

  int resultado = (a || !b) && c;
  printf("%i\n", resultado);



  return 0;
}