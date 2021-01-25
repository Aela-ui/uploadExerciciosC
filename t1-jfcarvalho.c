/*
  O programa sorteia um número aleatório inteiro entre 1 e 100, e pede
  para o usuário adivinhá-lo. A cada tentativa do usuário, o programa deve
  dizer se o valor está certo, ou se está abaixo ou acima do número sorteado. 
  Quando o usuário acertar o número, o programa deve informar o número de
  tentativas e oferecer uma nova partida.

  Pela Aluna: Jade Freire de Carvalho
*/

#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

/*
  É a função responsável pela soma das tentativas de adivinhar que o jogador fará
  usando a variável 'tentativas' e sempre somando +1(++) a cada uma das vezes.

  Também é a responsável pela comparação de igualdade, maior ou menor entre a entrada
  (valor que o jogador digitar) e o sorteado(valor aleatório escolhido pelo programa)
  utilizando o 'if' para a condição da comparação.

  Além disso, usa o 'printf', para conversar e informar o jogador com dicas e também
  o valor do 'sorteado' quando acertado e o número de tentativas até chegar nesse valor.

  Não possui valor de retorno nessa função.
*/

void jogo (int sorteado, int entrada, int tentativas){
  do {
    printf("Tente adivinhar o valor: ");
    tentativas ++;
    scanf("%d", &entrada);
    if(entrada==sorteado) {
      printf("Acertou!\n");
      printf("O numero de tentativas:%d\n", tentativas);
    }
    else if(entrada < sorteado) {
      printf("Dica: O numero deve ser maior\n");  
    }
    else {
      printf("Dica: O numero deve ser menor\n");
    }
  } while(entrada != sorteado);
}

int main () 
{
  int sorteado, entrada, tentativas = 0;
  char c = 'Y';
  srand(time(NULL));  
  while(c == 'Y' || c == 'y') { 
    sorteado = (rand()%100) + 1;
    tentativas = 0;
    jogo (sorteado, entrada, tentativas);
    printf("Quer continuar? (Y/N): ");
    printf("\n");
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    scanf("%c", &c);
  }
  return 0;
}








