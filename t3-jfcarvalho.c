/*
  O programa deve apresentar um tabuleiro de sudoku, e permitir que
  o usuário jogue nesse tabuleiro. O tabuleiro inicial deve ser lido
  de um arquivo, que contém 81 números entre 0 e 9, que são os valores
  de cada posição do tabuleiro.

  Pela aluna: Jade Freire de Carvalho
*/

#include <stdio.h>

/*
  É a função responsável por ler o arquivo do mapa;
  a variável 'jogo[9][9]'a qual representa a matriz do jogo
  que será lida e irá aparecer ao usuário;
  A variável 'char nome' representa o nome do arquivo e
  a quantidade de letras que podem ser usadas.

  Sem retorno.
*/

void ler_mapa (int jogo[9][9], char nome[20]) {
  FILE *arquivo; 
  int x, y;
  arquivo = fopen(nome, "r");
  if(arquivo == NULL){
    printf("Arquivo não encontrado\n");
    for(x = 0; x<9; x++){
      for(y = 0; y<9; y++){
        jogo[x][y] = 0;
      }
    }
    fclose(arquivo);
    return;
  }
  for (x = 0; x < 9; x++){
    for (y = 0; y < 9; y++){
      fscanf(arquivo, "%d", &jogo[x][y]);
    }
  }
  fclose(arquivo);
}

/*
  É a função responsável pela representação da matriz do 'jogo[9][9]'.
  A variável x é a linha.
  A variável y é a coluna.
  a variável 'jogo[9][9]'é responsável pela matriz do jogo
  
  Sem retorno.
*/

void mapa(int jogo[9][9]){
  int x, y;

  for (x = 0; x < 9; x++){
    for (y = 0; y < 9; y++){
      printf("%d ", jogo[x][y]);

    }
    printf ("\n");
  }
}

/*
  É a função responsável por salvar o mapa do arquivo;
  A variável x é a linha.
  A variável y é a coluna.
  a variável 'jogo[9][9]'é responsável pela matriz do jogo
  que será lida e irá aparecer ao usuário;
  A variável 'char nome' representa o nome do arquivo e
  a quantidade de letras que podem ser usadas.


  Sem retorno.
*/

void salvar_mapa (int jogo[9][9], char nome[20]) {
  FILE *arquivo; 
  int x, y;
  arquivo = fopen(nome, "w");
  for (x = 0; x < 9; x++){
    for (y = 0; y < 9; y++){
      fprintf (arquivo, "%d ", jogo[x][y]);
    }
  }
  fclose(arquivo);
}

/*
  Responsável por checar a linha que será feita a jogada do usuário.
  A variável y reprensenta a linha.
  A variável auxiliar serve para checar os números.
  A variável o contador para ver quantas vezes o numero se repete dentro da linha
  ou da coluna.

  Retorna 0(falso) para contador > 1.
  Retorna 1(verdadeiro) para auxiliar = jogo.
*/

int checa_linha(int jogo[9][9], int linha){
  int y, auxiliar, contador = 0;
  for(auxiliar = 1; auxiliar < 10; auxiliar++){
    for(y = 0; y < 9; y++){
      if(auxiliar == jogo[linha][y]){
        contador++;
      }
    }
    if(contador > 1){
        return 0;
      }  
    contador = 0;
  }
  return 1;
}



/*
  Responsável por checar a coluna que será feita a jogada do usuário.
  A variável x reprensenta a coluna.
  A variável auxiliar serve para checar os números.
  A variável o contador para ver quantas vezes o numero se repete dentro da linha
  ou da coluna.

  Retorna 0(falso) para contador > 1.
  Retorna 1(verdadeiro) para auxiliar = jogo.
*/

int checa_coluna(int jogo[9][9], int coluna){
  int x, auxiliar, contador = 0;
  for(auxiliar = 1; auxiliar < 10; auxiliar++){
    for(x = 0; x < 9; x++){
      if(auxiliar == jogo[x][coluna]){
        contador++;
      }
    }
    if(contador > 1){
        return 0;
      }  
    contador = 0;
  }
  return 1;
}

/*
  Responsável por checar o quadrante.
  A variável x representa a coluna.
  A variável y representa a linha.

  Retorna 0(falso) para contador > 1.
  Retorna 1(verdadeiro) para auxiliar = jogo.
  
*/

int checa_cubo(int jogo[9][9], int cubo){
  int aux[9][9], k = 0;

  for (int i = (cubo / 3) * 3; i < ((cubo / 3) * 3) + 3; i++) {
    for (int j = (cubo % 3) * 3; j < ((cubo % 3) * 3) + 3; j++) {
      aux[0][k++] = jogo[i][j];
    }
  }

  return checa_linha(aux, 0);
}

/*
  Reponsável por verificar a matriz do jogo, 
  no caso se a posição permite a jogada.
  A variável y representa linha.
  A variável x representa coluna.

  Retorna verdadeiro se a coluna e a linha coincidirem em uma posição vazia.
*/


int verificar(int jogo[9][9]){
  int x, y;
  for (x = 0; x < 9; x++){
    for (y = 0; y < 9; y++){
      if(jogo[x][y] == 0){
        return 0;
      }
    }
  }
  return 1;
}

/*
  Reponsável pela identificação da vitória do usuário.

  Retorna verdadeiro se a linha, coluna e cubo estiverem diferentes.
*/

int vitoria(int jogo [9][9]){
  int auxiliar;
  for(auxiliar = 0; auxiliar < 9; auxiliar++){
    if(!checa_linha(jogo, auxiliar) || !checa_coluna(jogo, auxiliar) || !checa_cubo(jogo, auxiliar)){
      return 0;
    }
  }
  return 1;
}

/*
  Reponsável por confirmar a saída do usuário do jogo.

  Retorna 1(verdadeiro), caso ele escolha deixar o jogo.
*/

int deixar(){
  int opcao;
  printf("Digite 1 para confirmar a saida\n");
  scanf("%d", &opcao);
  if(opcao == 1){
    return 1;
  }
  return 0;
}

/*
  Responsável por achar em qual cubo está a posição que o usuário digitou.
*/

int acha_cubo2(int x, int y)
{
  if(y >= 3 && y < 6 && x >= 3 && x < 6){
    return 4;
  }else if(y >= 6 && x >= 3 && x < 6 ){
    return 5;
  }else if(y < 3 && x >= 6){
    return 6;
  }else if(y >= 3 && y < 6 && x >= 6){
    return 7;
  }
  return 8;
}

/*
  Responsável por achar em qual cubo está a posição que o usuário digitou.

  Retorna a função acha_cubo2
*/

int acha_cubo1(int x, int y)
{
  if(x < 3 && y < 3){
    return 0;
  }else if(y >= 3 && y < 6 && x < 3){
    return 1;
  }else if(y >= 6 && x < 3){
    return 2;
  }else if(y < 3 && x >= 3 && x < 6){
    return 3;
  }
  return acha_cubo2(x, y);
}

/*
  Responsável por abrir um novo jogo.

  Sem retorno.
*/

void abrir_novo_jogo(int jogo[9][9], char nome[20]){
  printf("Digite o nome do jogo que quer carregar: \n");
  scanf(" %s", nome);
  ler_mapa(jogo, nome);
}

/*
  Reponsável por validar a jogada do usuário.

  Sem retorno.
*/

void validar(int jogo[9][9], int x, int y, int auxiliar){
  jogo[x-1][y-1] = auxiliar;
  if(checa_coluna(jogo, y - 1) && checa_linha(jogo, x - 1) &&
  checa_cubo(jogo, acha_cubo1(x - 1, y - 1))){jogo[x-1][y-1] = auxiliar;
  }else{
      jogo[x-1][y-1] = 0;
    printf("Tente denovo\n");
  }
}

/*
  Responsável por salvar o jogo.

  Sem retorno.
*/

void salva_jogo(int jogo[9][9], char nome[20]){
  printf("Digite o nome do seu jogo: \n");
  scanf("%s", nome);
  salvar_mapa(jogo, nome);
}

/*
  Responsável por auxiliar o usuário a jogar.

  Sem retorno.
*/

void jogar(int jogo[9][9], char nome[20], int x){
  int y, auxiliar;
  printf("Digite um numero de 1 a 9 (Primeiro a linha, Segundo a coluna, Terceiro o número que deseja): \n");
  scanf("%d %d", &y, &auxiliar);
  if(y>0 && y<10 && auxiliar>0 && auxiliar<10){
    validar(jogo, x, y, auxiliar);
    salvar_mapa(jogo, nome);
  }else{
    printf("Tente denovo\n");
    return;
  }  
}

/*
  Responsável pela jogada do usuário.

  Retorna a opção escolhida.
*/

int jogada(int jogo[9][9], char nome[20]){
  char opcao;
  printf("Digite a linha primeiro (1 a 9)\nDigite a coluna (1 a 9)\nDigite o numero que deseja por\nDigite 'g' gravar o estado atual do jogo\nDigite 'l' para ler o jogo salvo anteriormente\nDigite 's' para sair do jogo\n");
  scanf(" %c", &opcao);
  if(opcao == '1' || opcao == '2' || opcao == '3' || opcao == '4' || opcao == '5'
  || opcao == '6' || opcao == '7' || opcao == '8' || opcao == '9' ){
    jogar(jogo, nome, (int) opcao - '0');
  }else if(opcao == 'g'){
    salva_jogo(jogo, nome);
  }else if(opcao == 'l'){
    abrir_novo_jogo(jogo, nome);
  }else if(opcao == 's'){
    return deixar();
  }else{
    printf("Comando errado\n");
  }
  return 0;
}

int main(){
  int jogo[9][9], sair; 
  char nome[20];
  abrir_novo_jogo(jogo, nome);
  printf("O valor 0 representa as casas vazias\n");
  do{
    mapa(jogo);
    sair = jogada(jogo, nome);
    if(sair){
      return 0;
    }
  }while(!verificar(jogo));
  if(vitoria(jogo)){
    printf("Voce venceu");
  }else {
    printf("Voce perdeu");
  }
  return 0;
}