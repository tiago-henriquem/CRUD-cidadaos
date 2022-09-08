#include<stdio.h>
#include<string.h>
/*
  Nota:
    -> variáveis de alteração: são variáveis que vão alterar os elementos principais da aplicação (cidadãos e filas)
    -> variáveis de interação: são variáveis cujos valores são obtidos pela interação com o usuário (variáveis de resposta)
*/
#define MAX_cidadaos 3
#define MAX_FILA 100

typedef struct {
  char nome[31];
  int codigo;
  int idade;
  char uf[3];
} Cidadao;

typedef struct {
  int codigoCidadao;
  char tipoAtendimento[12];
  int senha;
} Fila;

void menuInicial(int *contador, Cidadao cidadaos[], Fila fila[]);

void menuCidadao(int *contador, Cidadao cidadaos[], Fila fila[]);

void cadastraCidadao(int *contador, Cidadao cidadaos[], Fila fila[]);

int verificaCodigoExistente(int *contador, Cidadao cidadaos[], int codigo);

void menuPesquisarPorCodigo(int *contador, Cidadao cidadaos[], Fila fila[]);

void menuAtualizarCadastro(int *contador, Cidadao cidadaos[], Fila fila[]);

void menuExcluirCadastro(int *contador, Cidadao cidadaos[], Fila fila[]);

void menuGerarSenha(int *contador, Cidadao cidadaos[], Fila fila[]);

void imprimeCidadao(int *contador, Cidadao cidadaos[], Fila fila[]);


int main() {
  int i=0;
  Cidadao cidadaos[MAX_cidadaos];
  Fila fila[MAX_FILA];
  menuInicial(&i, cidadaos, fila);
  return 0;
}

void menuInicial(int *contador, Cidadao cidadaos[], Fila fila[]) {
  /* essa função recebe o valor do ponteiro *contador */
  char resposta[2];
  printf("\n1 CIDADÂO\n");
  printf("2 GERAR SENHA\n");
  printf("3 ATENDIMENTO AO CIDADÂO\n");
  printf("S Sair\n\n");
  scanf("%s", resposta);
  if(strcmp(resposta, "1")==0) {
    /* passa para a função menuCidadao o endereço do ponteiro *contador */
    menuCidadao(contador, cidadaos, fila);
  } else if(strcmp(resposta, "2")==0) {
    menuGerarSenha(contador, cidadaos, fila);
  } else if(strcmp(resposta,"S")==0) {
    printf("Saindo...\n");
  } else {
    printf("Escolha uma opção válida!");
    menuInicial(contador, cidadaos, fila);
  }
}

void menuCidadao(int *contador, Cidadao cidadaos[], Fila fila[]) {
  char resposta[2];
  printf("\n1 CADASTRAR\n");
  printf("2 PESQUISAR POR CÒDIGO\n");
  printf("3 ATUALIZAR CADASTRO\n");
  printf("4 EXCLUIR CADASTRO\n");
  printf("0 VOLTAR\n\n");
  scanf("%s", resposta);
  if(strcmp(resposta, "1")==0) {
    cadastraCidadao(contador, cidadaos, fila);
  } else if(strcmp(resposta, "2")==0) {
    menuPesquisarPorCodigo(contador, cidadaos, fila);
  } else if(strcmp(resposta, "3")==0) {
    menuAtualizarCadastro(contador, cidadaos, fila);
  } else if(strcmp(resposta, "4")==0) {
    menuExcluirCadastro(contador, cidadaos, fila);
  } else if(strcmp(resposta,"0")==0) {
    menuInicial(contador, cidadaos, fila);
  } else {
    printf("Escolha uma opção válida!");
    menuCidadao(contador, cidadaos, fila);
  }
}

void cadastraCidadao(int *contador, Cidadao cidadaos[], Fila fila[]) {
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
    imprimeCidadao(contador, cidadaos, fila);
  } else {
    printf("O código informado já está cadastrado.\n Faça um novo cadastro inserindo um código diferente.\n");
    menuCidadao(contador, cidadaos, fila);
  }
}

void imprimeCidadao(int *contador, Cidadao cidadaos[], Fila fila[]) {
  printf("\n contador: %i\n", *contador);
  printf("Nome: %s\n", cidadaos[*contador-1].nome);
  printf("Idade: %i\n", cidadaos[*contador-1].idade);
  printf("Codigo: %i\n", cidadaos[*contador-1].codigo);
  printf("UF: %s\n", cidadaos[*contador-1].uf);
  menuCidadao(contador, cidadaos, fila);
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

void menuPesquisarPorCodigo(int *contador, Cidadao cidadaos[], Fila fila[]) {
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
    menuCidadao(contador, cidadaos, fila);
  } else {
    printf("O código informado não existe. Tente novamente.\n");
    menuCidadao(contador, cidadaos, fila);
  }
}

void menuAtualizarCadastro(int *contador, Cidadao cidadaos[], Fila fila[]) {
  /* Variáveis de interação */
  int atualizarCodigoInformado, atualizarPosicaoCidadaoExistente;
  char atualizarResposta[2];
  /* Variáveis de alteração */
  int novaIdade;
  char novoNome[31], novaUF[3];
  printf("\nQual é o código do usuário que deseja atualizar? ");
  scanf("%i", &atualizarCodigoInformado);
  /* Verifica se existe e caso existir, armazena a posição em que se encontra */
  atualizarPosicaoCidadaoExistente = verificaCodigoExistente(contador, cidadaos, atualizarCodigoInformado);
  /* Se existir, pergunta ao usuário o campo que deseja alterar */
  if(atualizarPosicaoCidadaoExistente==-1) {
    printf("\nUsuário não encontrado no sistema. Tente novamente.\n");
    menuCidadao(contador, cidadaos, fila);
  } else {
    printf("\nQual campo deseja alterar?\n");
    printf("N - Nome\n");
    printf("I - Idade\n");
    printf("U - UF\n");
    scanf("%s", atualizarResposta);

    if(strcmp(atualizarResposta, "N")==0) {
      printf("\nInforme o novo nome: ");
      scanf("%s", novoNome);
      strcpy(cidadaos[atualizarPosicaoCidadaoExistente].nome,novoNome);
      printf("\nCampo atualizado com sucesso!\n");
      menuCidadao(contador, cidadaos, fila);
    } else if(strcmp(atualizarResposta, "I")==0) {
      printf("\nInforme a nova idade: ");
      scanf("%i", &novaIdade);
      cidadaos[atualizarPosicaoCidadaoExistente].idade = novaIdade;
      printf("\nCampo atualizado com sucesso!\n");
      menuCidadao(contador, cidadaos, fila);
    } else if(strcmp(atualizarResposta, "U")==0) {
      printf("\nInforme a nova UF: ");
      scanf("%s", novaUF);
      strcpy(cidadaos[atualizarPosicaoCidadaoExistente].uf,novaUF);
      printf("\nCampo atualizado com sucesso!\n");
      menuCidadao(contador, cidadaos, fila);
    } else {
      printf("\nOpção inválida. Tente novamente. \n");
      menuAtualizarCadastro(contador, cidadaos, fila);
    }
  }
}

void menuExcluirCadastro(int *contador, Cidadao cidadaos[], Fila fila[]) {
  /* Variáveis de interação */
  int excluirCodigoInformado, excluirPosicaoCidadaoExistente, i;
  char excluirResposta[2];
  printf("\n\nentrou \n\n");
  printf("\nQual é o código do usuário que deseja excluir? ");
  scanf("%i", &excluirCodigoInformado);
  excluirPosicaoCidadaoExistente = verificaCodigoExistente(contador, cidadaos, excluirCodigoInformado);
  if(excluirPosicaoCidadaoExistente!=-1) {
    printf("Tem certeza que deseja excluir?\n");
    printf("S - Sim\n");
    printf("N - Não\n");
    scanf("%s", excluirResposta);
    if(strcmp(excluirResposta, "S")==0) {
      for(i=excluirPosicaoCidadaoExistente; i<*contador-1; i++) {
        strcpy(cidadaos[i].nome,cidadaos[i+1].nome);
        cidadaos[i].idade = cidadaos[i+1].idade;
        cidadaos[i].codigo = cidadaos[i+1].codigo;
        strcpy(cidadaos[i].uf,cidadaos[i+1].uf);
      }
      *contador -= 1;
      printf("Usuário excluído com sucesso!");
      menuCidadao(contador, cidadaos, fila);
    } else if(strcmp(excluirResposta, "N")==0) {
      printf("Nenhum usuário foi excluído.\n");
      menuCidadao(contador, cidadaos, fila);
    } else {
      printf("Opção inválida. Tente novamente.\n");
      menuCidadao(contador, cidadaos, fila);
    }
  } else {
    printf("\nUsuário não encontrado no sistema. Tente novamente.\n");
    menuCidadao(contador, cidadaos, fila);
  }
}

void menuGerarSenha(int *contador, Cidadao cidadaos[], Fila fila[]) {
  /* Variáveis de alteração */
  int codigoCidadao, senha;
  char tipoAtendimento[12];
}