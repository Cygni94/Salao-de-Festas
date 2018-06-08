#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    long int codigo, telefone, dataNasc;
    char nome[50], endereco[100];
} novoCliente;

void cadastroCliente();
void Pesquisa();
int linhaDisponivel(int);

FILE *arquivo;

int main() {
    cadastroCliente();
    printf("retornou e fim");
    return 0;
}

void cadastroCliente () {
    novoCliente Cliente;
    Cliente.codigo = linhaDisponivel(1);
    arquivo = fopen("clientes.txt","a");

    printf("***** Cadastro de clientes *****\n\n");
    printf("Digite o nome: ");
    gets(Cliente.nome);
    printf("Digite o endereco: ");
    gets(Cliente.endereco);
    printf("Digite o telefone(apenas numeros, 8 ou 9 digitos): ");
    scanf("%ld", &Cliente.telefone);
    printf("Digite a data de nascimento(apenas numeros): ");
    scanf("%ld", &Cliente.dataNasc);
    fprintf(arquivo, "%ld", Cliente.codigo);
    fputs("|",arquivo);
    fputs(Cliente.nome, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.endereco, arquivo);
    fputs("|",arquivo);
    fprintf(arquivo, "%lu", Cliente.telefone);
    fputs("|",arquivo);
    fprintf(arquivo, "%lu", Cliente.dataNasc);
    fputs("\n", arquivo);
    fclose(arquivo);

    printf("O cliente %s foi registrado com sucesso. Codigo do cliente: %lu\n", Cliente.nome, Cliente.codigo);
    return ;
}

int linhaDisponivel (int opcao) {
    int contadorLinhas=0;
    char ch;

    switch(opcao) {
    case 1:
        arquivo = fopen("clientes.txt", "r");
        while ((ch=getc(arquivo)) != EOF) {
            if (ch == '\n') {
                ++contadorLinhas;
            }
        }
        fclose(arquivo);
        break;
    }
    return contadorLinhas;
}
