#include <stdio.h>

// Pede ao usuário informar para onde deseja que a peça vá
void deseja(int posicoes[2]){
  printf("Digite a linha que deseja que a peca va: \n");
  scanf("%d", &posicoes[0]);
  printf("Digite a coluna que deseja que a peca va: \n");
  scanf("%d", &posicoes[1]);

  posicoes[0] = posicoes[0] - 1;
  posicoes[1] = posicoes[1] - 1;
}

void percorre_matriz(int posicoes[2], char peca, char tabuleiro[7][7])
{
  for (int l = 0; l < 7; l++){
    for (int v = 0; v < 7; v++){
      if (peca == tabuleiro[l][v]) {
        posicoes[0] = l;
        posicoes[1] = v;
      }
    }
  }
}

int valida_jogada(int posicoes_futuras[2], int posicoes_atuais[2], char peca, char tabuleiro[7][7])
{
  int distancia_linha = posicoes_atuais[0] - posicoes_futuras[0];
  int distancia_coluna = posicoes_atuais[1] - posicoes_futuras[1];

  switch (peca) {
    case 'A':
      if ((distancia_linha == 1 && distancia_coluna == 0) ||
          (distancia_linha == 0 && distancia_coluna == 1 || distancia_coluna == -1)) {
        return 1;
      } else {
        return 0;
      }
    case 'L':
      if ((distancia_linha == 1 || distancia_linha == -1) && 
          (distancia_coluna == 1 || distancia_coluna == -1)) {
        return 1;
      } else {
        return 0;
      }
    case 'M':
      if (((distancia_linha == 2 || distancia_linha == -2) && distancia_coluna == 0) ||
          (distancia_linha == 0 && distancia_coluna == 2 || distancia_coluna == -2)) {
        return 1;
      } else {
        return 0;
      }
    case 'k':
    case 'K':
      if ((distancia_linha == 3 && distancia_coluna == 0) ||
          (distancia_linha == 0 && (distancia_coluna == 3 || distancia_coluna == -3)) ||
          (distancia_linha == 3 && (distancia_coluna == 3 || distancia_coluna == -3))) {
        return 1;
      } else {
        return 0;
      }
  }
}

void move(int posicoes_futuras[2], int posicoes_atuais[2], char peca, char tabuleiro[7][7])
{
  int linha_fut = posicoes_futuras[0];
  int coluna_fut = posicoes_futuras[1];

  int linha_atual = posicoes_atuais[0];
  int coluna_atual = posicoes_atuais[1];

  if (tabuleiro[linha_fut][coluna_fut] == '+') {
    if (valida_jogada(posicoes_futuras, posicoes_atuais, peca, tabuleiro)) {
      tabuleiro[linha_fut][coluna_fut] = peca;
      tabuleiro[linha_atual][coluna_atual] = '+';
    } else {
      printf("\nJogada invalida, tente denovo \n");
    }
  } else {
    printf("\nJogada invalida, \n");
  }
}

void mostrar(char tabuleiro[7][7]) {
  for (int l = 0; l < 7; l++){
    for (int v = 0; v < 7; v++){
      printf("%c ", tabuleiro[l][v]);
    }
    printf("\n");
  }
}

int main(void){
  char tabuleiro [7][7] ={{'+', '+', '+', '+', '+', '+', 'Z'}, 
                          {'+', '+', '+', '+', '+', '+', '+'},
                          {'+', '+', '+', '+', '+', '+', '+'},
                          {'+', '+', '+', '+', '+', '+', '+'},
                          {'+', '+', '+', '+', '+', '+', '+'},
                          {'+', '+', '+', '+', '+', '+', '+'},
                          {'K', 'A', 'L', '+', 'M', '+', 'k'}};

  int posicoes_futuras[2];
  int posicoes_atuais[2];
  char peca;
  while (1) {
  mostrar(tabuleiro);

  printf("Digite a peca ou '0' para sair: \n");
  peca = getchar();
    if(peca == '0'){
      return 0;
    }
    // pegar a posição da peça
    percorre_matriz(posicoes_atuais, peca, tabuleiro);

    // onde vai a peça
    deseja(posicoes_futuras);
    move(posicoes_futuras, posicoes_atuais, peca, tabuleiro);
  }

}