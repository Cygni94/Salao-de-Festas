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
    unsigned long int codigo;
    char nome[100], endereco[100];
    arquivo = fopen("nome.txt","a+");
    printf("***** Cadastro de clientes *****\n\n");
    codigo = rand() % 100;
    printf("Digite o nome:");
    gets(nome);
    printf("Digite o endereco:");
    gets(endereco);
    fputs(nome, arquivo);
    fputs("|",arquivo);
    fputs(endereco, arquivo);
    fputs("|",arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);
    return;

}
