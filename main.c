#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    long int codigo, telefone, dataNasc;
    char nome[50], endereco[100];
} novoCliente;

void cadastroCliente();

int main() {
    cadastroCliente();
    printf("retornou e fim");
    return 0;
}

void cadastroCliente () {
    FILE *arquivo;
    int i;
    char nome[100], endereco[100];
    arquivo = fopen("nome.txt","w");
    printf("***** Cadastro de clientes *****\n\n");
    printf("Digite o nome:");
    gets(nome);
    fputs(nome, arquivo);
    fputs("|",arquivo);
    printf("Digite o endereco:");
    gets(endereco);
    fputs(endereco, arquivo);
    fputs("|",arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);
    return;

}
