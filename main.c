#include<stdio.h>
#include<string.h>

#define MAX_cidadaos 3

typedef struct {
  char nome[31];
  int codigo;
  int idade;
  char uf[3];
} Cidadao;

void menuInicial(int *contador, Cidadao cidadaos[]);

void menuCidadao(int *contador, Cidadao cidadaos[]);

void cadastraCidadao(int *contador, Cidadao cidadaos[]);

int verificaCodigoExistente(int *contador, Cidadao cidadaos[], int codigo);

void menuPesquisarPorCodigo(int *contador, Cidadao cidadaos[]);

void imprimeCidadao(int *contador, Cidadao cidadaos[]);


int main() {
  int i=0;
  Cidadao cidadaos[MAX_cidadaos];
  menuInicial(&i, cidadaos);
  return 0;
}

void menuInicial(int *contador, Cidadao cidadaos[]) {
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
    menuCidadao(contador, cidadaos);
  } else if(strcmp(resposta,"S")==0) {
    printf("Saindo...\n");
  } else {
    printf("Escolha uma opção válida!");
    menuInicial(contador, cidadaos);
  }
}

void menuCidadao(int *contador, Cidadao cidadaos[]) {
  char resposta[2];
  printf("\n1 CADASTRAR\n");
  printf("2 PESQUISAR POR CÒDIGO\n");
  printf("3 ATUALIZAR CADASTRO\n");
  printf("4 EXCLUIR CADASTRO\n");
  printf("0 VOLTAR\n\n");
  scanf("%s", resposta);
  if(strcmp(resposta, "1")==0) {
    cadastraCidadao(contador, cidadaos);
  } else if(strcmp(resposta, "2")==0) {
    menuPesquisarPorCodigo(contador, cidadaos);
  } else if(strcmp(resposta,"0")==0) {
    menuInicial(contador, cidadaos);
  } else {
    printf("Escolha uma opção válida!");
    menuCidadao(contador, cidadaos);
  }
}

void cadastraCidadao(int *contador, Cidadao cidadaos[]) {
  int idade, codigo, codigoExiste;
  char nome[31], uf[3];
  printf("Informe o nome: ");
  scanf("%s", nome);
  printf("\nInforme a idade: ");
  scanf("%i", &idade);
  printf("\nInforme o código: ");
  scanf("%i", &codigo);
  /* Verifica se já existe algum cadastro com o código informado */
  codigoExiste = verificaCodigoExistente(contador, cidadaos, codigo);
  if(codigoExiste==-1) {
    printf("\nInforme a UF: ");
    scanf("%s", uf);
    strcpy(cidadaos[*contador].nome, nome);
    cidadaos[*contador].idade = idade;
    cidadaos[*contador].codigo = codigo;
    strcpy(cidadaos[*contador].uf, uf);
    *contador += 1;
    imprimeCidadao(contador, cidadaos);
  } else {
    printf("O código informado já está cadastrado.\n Faça um novo cadastro inserindo um código diferente.\n");
    menuCidadao(contador, cidadaos);
  }
}

void imprimeCidadao(int *contador, Cidadao cidadaos[]) {
  printf("\n contador: %i\n", *contador);
  printf("Nome: %s\n", cidadaos[*contador-1].nome);
  printf("Idade: %i\n", cidadaos[*contador-1].idade);
  printf("Codigo: %i\n", cidadaos[*contador-1].codigo);
  printf("UF: %s\n", cidadaos[*contador-1].uf);
  menuCidadao(contador, cidadaos);
}

/* Retorna -1 caso não exista o cidadão no sistema. Do contrário, retorna a posição dele */
int verificaCodigoExistente(int *contador, Cidadao cidadaos[], int codigo) {
  int i;
  for(i=0; i<*contador; i++) {
    if(codigo==cidadaos[i].codigo) {
      return i;
    }
  }
  return -1;
}

void menuPesquisarPorCodigo(int *contador, Cidadao cidadaos[]) {
  int codigoInformado, posicaoCidadaoExistente;
  printf("Informe o código do cidadão que deseja buscar no sistema: ");
  scanf("%i", &codigoInformado);
  /* Verifica se o código existe */
  posicaoCidadaoExistente = verificaCodigoExistente(contador, cidadaos, codigoInformado);
  /* Se existir, exibe os dados do cidadão e volta para o menu anterior */
  if(posicaoCidadaoExistente!=-1) {
    printf("Nome: %s\n", cidadaos[posicaoCidadaoExistente].nome);
    printf("Idade: %i\n", cidadaos[posicaoCidadaoExistente].idade);
    printf("Codigo: %i\n", cidadaos[posicaoCidadaoExistente].codigo);
    printf("UF: %s\n", cidadaos[posicaoCidadaoExistente].uf);
    menuCidadao(contador, cidadaos);
  } else {
    printf("O código informado não existe. Tente novamente.\n");
    menuCidadao(contador, cidadaos);
  }
}