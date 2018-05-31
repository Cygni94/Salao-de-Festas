#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    int codigo, telefone, dataNasc;
    char nome[50], endereco[100];
} Cliente;

int main() {
    int opcao;
    int i = 0;

    printf("####SALAO DE FESTAS####\n#####PATATI PATATA#####\n\n");
    //Menu principal
    printf("\nMenu:\n1-Cadastrar cliente\n2-Cadastrar funcionario\n3-Cadastrar fornecedor\n4-Cadastrar uma festa\n");
    printf("5-Fazer um orcamento\n6-Atualizar status de contrato\n7-Consultas de informacoes cadastrais\n8-Relatorio de festas\n");
    printf("9-Relatorios de festas\n");
    //Submenu 7 - Informacoes cadastrais
    //Submenu 9 - Relatorios de festas
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:

        Cliente i;
        printf("Digite o nome do cliente ");
        gets(i.nome);
        printf("Digite o endereco do cliente: ");
        printf("Digite o telefone do cliente: ");
        printf("Digite a data de nascimento do cliente: ");

        break;
    }
    return 0;
}
