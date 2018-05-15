#include <stdio.h>
#include <stdlib.h>

int main() {
    int colunas = 10;//temporariamente será usada uma quantidade fixa de colunas, depois especificar quantidade ideal para cada campo.
    int cliente[4][colunas], funcionario[5][colunas], fornecedor[3][colunas], festa[5][colunas], contrato[6][colunas];
    char clienteLabel[] = {'Nome', 'Endereco', 'Telefone', 'Data de Nascimento'};
    int i, j, opcao;

    printf("O que voce deseja cadastrar?\n");
    printf("1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Festa\n5-Contrato\n");
    scanf("%d", &opcao);
    //USAR CONSTRUCTOR!!!!!
    switch(opcao) {

    case 1:
        printf("Cliente");

        for (i=0; i<colunas; i++) {
            printf("Codigo: %d\n", i);
            for (j=0; j<4; j++) {
                printf("%s", clienteLabel[j]);
                scanf("%s", cliente[i][j]);
            }
        }
        break;
    }
    return 0;
}
