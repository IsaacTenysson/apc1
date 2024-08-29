#include <stdio.h>

int main (){
 long int isbn = 1234567891011;
 short int num_paginas = 42;
 float preco_livro = 9.90f;
 short int ano_pub = 1983;

  printf("ISBN: %li\n", isbn);
  printf("Num. Paginas: %i\n", num_paginas);
  printf("Preco: R$ %.2f\n", preco_livro);
  printf("Publicado em: %i\n ", ano_pub);
  
  return 0;
}