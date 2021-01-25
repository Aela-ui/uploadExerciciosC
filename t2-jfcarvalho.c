/*
  O programa deve adivinhar um número entre 1 e 100 escolhido
  pelo usuário. O programa deve pedir para o usuário escolher
  um número, e depois propor valores para esse número. A cada
  número proposto pelo programa, deve pedir ao usuário informação
  sobre se seu número é igual, maior ou menor que o número escolhido.
  O programa deve usar essa informação para a próxima escolha.
  O programa deve identificar se o usuário estiver mentindo.
  O programa deve propor uma nova partida no final.

  Pela aluna: Jade Freire de Carvalho
*/

#include <stdio.h> 

/*
  É a função responsável por dizer se o usuário está mentindo quando entra
  em contradição, usando argumentos que vem de variáveis da função 'jogo'.
  A variável 'primeiro' é o valor mínimo possível.
  A variável 'final' é o valor máximo possível.
  A variável 'escolhido', é o valor proposto pelo sistema.
  A variável 'guardadorSimbolo' guarda o símbolo de '<', '>' ou '='.

  O retorno da função é '0' se não estiver mentindo e '1' se estiver mentindo. 
*/

int mentira(int primeiro, int final, int escolhido, char guardadorSimbolo){
  if(primeiro == escolhido && guardadorSimbolo == '<'){
    printf("Mentiroso\n");
    return 1;
  }
  if(final == escolhido && guardadorSimbolo == '>'){
    printf("Mentiroso\n");
    return 1;
  }
  return 0;
}

/*
  É a função escolha é para receber o símbolo digitado pelo usuário.
  A variável 'escolhido', é o valor proposto pelo sistema.

  Retorna o símbolo decidido pelo usuário.
*/

char escolha(int escolhido){
  char guardadorSimbolo;
  printf("Se o numero %d eh maior, digite >, eh menor, digite <, igual, digite =\n", escolhido);
  scanf(" %c", &guardadorSimbolo); 
  return guardadorSimbolo;
}

/*
  É a função responsável pela descoberta do número escolhido pelo usuário,
  A variável 'primeiro' é o valor mínimo possível.
  A variável 'final' é o valor máximo possível.
  A variável 'escolhido', é o valor proposto pelo sistema.
  A variável 'guardadorSimbolo' guarda o símbolo de '<', '>' ou '='.

  Sem retorno.
*/

void jogo () {
  int escolhido , final = 100, primeiro = 1;
  char guardadorSimbolo;
  do {
    escolhido = primeiro + (final - primeiro) / 2;
    guardadorSimbolo = escolha(escolhido);
    if(mentira(primeiro, final, escolhido, guardadorSimbolo)){
      return;
    }else if (guardadorSimbolo == '<'){
      final = escolhido - 1;      
    }else if (guardadorSimbolo == '>'){
      primeiro = escolhido + 1;  
    }else if(guardadorSimbolo == '='){
      printf("Acertei! ");
    }
  } while(guardadorSimbolo != '=');
}

int main (){
  char c = 'Y';
  while(c == 'Y' || c == 'y') {
    printf("Pense em um numero!\n");
    jogo();
    printf("Quer continuar? (Y/N): ");
    printf("\n");
    scanf(" %c", &c);
  }
  return 0;
}






