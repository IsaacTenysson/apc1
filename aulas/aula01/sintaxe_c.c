/* // ISSO eh diferente de isso 
// aqui eh para calcular a area do retangulo 
area_retangulo = base * altura;
/* comenta trecho  */

/*
blocos { }

main() {
// sempre terminar a linha de codigo com ponto e virgula
  linha_de_codigo;
  comando1;
  comando2;

}

*/

#include <stdio.h> //inclusao de bibliotecas

int main(){ // funcao principal
  // seu codigo aqui 

  // 1. entrada 
  //levantar meus ingredientes
  //char, int, float
  //variaveis
  //leitura 
  int primeiro_numero;
  int segundo_numero;
    
  primeiro_numero = 5;
  segundo_numero = 6;
  //2. processamento
  //calculos soma, subtracao, multiplicacao, divisao

  int soma = primeiro_numero + segundo_numero;
  
  //3. saida
  //escrita
  
  printf("A soma de %i com %i eh %i\n", primeiro_numero, segundo_numero, soma);
    
  return 0; //return fim do programa
}