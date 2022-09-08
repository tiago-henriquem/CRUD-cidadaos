#include<stdio.h>
#include<string.h>

#define MAX_CIDADOES 3

typedef struct {
  char nome[31];
  int codigo;
  int idade;
  char uf[3];
} Cidadao;

void menuInicial(int *contador, Cidadao cidadoes[]);

void menuCidadao(int *contador, Cidadao cidadoes[]);

void cadastraCidadao(int *contador, Cidadao cidadoes[]);

int verificaCodigoExistente(int *contador, Cidadao cidadoes[], int codigo);

void menuPesquisarPorCodigo(int *contador, Cidadao cidadoes[]);

void imprimeCidadao(int *contador, Cidadao cidadoes[]);


int main() {
  int i=0;
  Cidadao cidadoes[MAX_CIDADOES];
  menuInicial(&i, cidadoes);
  return 0;
}

void menuInicial(int *contador, Cidadao cidadoes[]) {
  /* essa função recebe o valor do ponteiro *contador */
  char resposta[2];
  printf("\nOlha o contador menu inicial: %i\n\n", *contador);
  printf("\n1 CIDADÂO\n");
  printf("2 GERAR SENHA\n");
  printf("3 ATENDIMENTO AO CIDADÂO\n");
  printf("S Sair\n\n");
  scanf("%s", resposta);
  if(strcmp(resposta, "1")==0) {
    /* passa para a função menuCidadao o endereço do ponteiro *contador */
    menuCidadao(contador, cidadoes);
  } else if(strcmp(resposta,"S")==0) {
    printf("Saindo...\n");
  } else {
    printf("Escolha uma opção válida!");
    menuInicial(contador, cidadoes);
  }
}

void menuCidadao(int *contador, Cidadao cidadoes[]) {
  char resposta[2];
  printf("\n1 CADASTRAR\n");
  printf("2 PESQUISAR POR CÒDIGO\n");
  printf("3 ATUALIZAR CADASTRO\n");
  printf("4 EXCLUIR CADASTRO\n");
  printf("0 VOLTAR\n\n");
  scanf("%s", resposta);
  if(strcmp(resposta, "1")==0) {
    cadastraCidadao(contador, cidadoes);
  } else if(strcmp(resposta, "2")==0) {
    menuPesquisarPorCodigo(contador, cidadoes);
  } else if(strcmp(resposta,"0")==0) {
    menuInicial(contador, cidadoes);
  } else {
    printf("Escolha uma opção válida!");
    menuCidadao(contador, cidadoes);
  }
}

void cadastraCidadao(int *contador, Cidadao cidadoes[]) {
  int idade, codigo, codigoExiste;
  char nome[31], uf[3];
  printf("Informe o nome: ");
  scanf("%s", nome);
  printf("\nInforme a idade: ");
  scanf("%i", &idade);
  printf("\nInforme o código: ");
  scanf("%i", &codigo);
  /* Verifica se já existe algum cadastro com o código informado */
  codigoExiste = verificaCodigoExistente(contador, cidadoes, codigo);
  if(codigoExiste==-1) {
    printf("\nInforme a UF: ");
    scanf("%s", uf);
    strcpy(cidadoes[*contador].nome, nome);
    cidadoes[*contador].idade = idade;
    cidadoes[*contador].codigo = codigo;
    strcpy(cidadoes[*contador].uf, uf);
    *contador += 1;
    imprimeCidadao(contador, cidadoes);
  } else {
    printf("O código informado já está cadastrado.\n Faça um novo cadastro inserindo um código diferente.\n");
    menuCidadao(contador, cidadoes);
  }
}

void imprimeCidadao(int *contador, Cidadao cidadoes[]) {
  printf("\n contador: %i\n", *contador);
  printf("Nome: %s\n", cidadoes[*contador-1].nome);
  printf("Idade: %i\n", cidadoes[*contador-1].idade);
  printf("Codigo: %i\n", cidadoes[*contador-1].codigo);
  printf("UF: %s\n", cidadoes[*contador-1].uf);
  menuCidadao(contador, cidadoes);
}

/* Retorna -1 caso não exista o cidadão no sistema. Do contrário, retorna a posição dele */
int verificaCodigoExistente(int *contador, Cidadao cidadoes[], int codigo) {
  int i;
  for(i=0; i<*contador; i++) {
    if(codigo==cidadoes[i].codigo) {
      return i;
    }
  }
  return -1;
}

void menuPesquisarPorCodigo(int *contador, Cidadao cidadoes[]) {
  int codigoInformado, posicaoCidadaoExistente;
  printf("Informe o código do cidadão que deseja buscar no sistema: ");
  scanf("%i", &codigoInformado);
  /* Verifica se o código existe */
  posicaoCidadaoExistente = verificaCodigoExistente(contador, cidadoes, codigoInformado);
  /* Se existir, exibe os dados do cidadão e volta para o menu anterior */
  if(posicaoCidadaoExistente!=-1) {
    printf("Nome: %s\n", cidadoes[posicaoCidadaoExistente].nome);
    printf("Idade: %i\n", cidadoes[posicaoCidadaoExistente].idade);
    printf("Codigo: %i\n", cidadoes[posicaoCidadaoExistente].codigo);
    printf("UF: %s\n", cidadoes[posicaoCidadaoExistente].uf);
    menuCidadao(contador, cidadoes);
  } else {
    printf("O código informado não existe. Tente novamente.\n");
    menuCidadao(contador, cidadoes);
  }
}