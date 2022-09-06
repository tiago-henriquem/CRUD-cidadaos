#include<stdio.h>
#include<string.h>

void menuInicial(int *contador);

void menuCidadao(int *contador);

void cadastraUsuario(int *contador);

int main() {
    int i=0;
    menuInicial(&i);
    return 0;
}

void menuInicial(int *contador) {
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
        menuCidadao(contador);
    } else if(strcmp(resposta,"S")==0) {
        printf("Saindo...\n");
    } else {
        printf("Escolha uma opção válida!");
        menuInicial(contador);
    }
}

void menuCidadao(int *contador) {
    char resposta[2];
    /* printf("\nOlha o contador menu cidadao: %i\n\n", *contador); */
    printf("\n1 CADASTRAR\n");
    printf("2 PESQUISAR POR CÒDIGO\n");
    printf("3 ATUALIZAR CADASTRO\n");
    printf("4 EXCLUIR CADASTRO\n");
    printf("0 VOLTAR\n\n");
    scanf("%s", resposta);
    if(strcmp(resposta, "1")==0) {
        /* passa para a função menuCidadao o endereço do ponteiro *contador */
        cadastraUsuario(contador);
    } else if(strcmp(resposta,"0")==0) {
        menuInicial(contador);
    } else {
        printf("Escolha uma opção válida!");
        menuCidadao(contador);
    }
}

void cadastraUsuario(int *contador) {
    /* pega o valor contido no ponteiro *contador, que é o valor apontado no i da main */
    *contador += 1;
    printf("Usuário cadastrado com sucesso!\n");
    menuCidadao(contador);
}