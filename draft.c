//scanf unsigned long int: https://stackoverflow.com/questions/12147352/format-specifier-for-scanning-long-unsigned-int
//search string in file: https://www.quora.com/How-do-I-search-from-a-text-file-in-c-language
//fseek (trocar em aberto para pago): https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
//vetor de struct em C: https://pt.stackoverflow.com/questions/173464/vetor-de-struct-em-c
//fprintf: https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    long int codigo, telefone, dataNasc;
    char nome[50], endereco[100];
} novoCliente;

void cadastroCliente();
void Pesquisa();
int linhaDisponivel(char);

FILE *arquivo;
char nomeArquivo[100];

int main() {
    cadastroCliente();
//    Pesquisa();
    printf("retornou e fim");
    return 0;
}

void cadastroCliente () {
    arquivo = fopen("clientes.txt","a+");
    novoCliente Cliente;
    nomeArquivo[15] = "clientes.txt";

    printf("nome %s\n\n", nomeArquivo);

    Cliente.codigo = linhaDisponivel(nomeArquivo);

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

/* void Pesquisa() {
    FILE *arquivo = fopen("clientes.txt","r");
    char nome[] = "europe";
    while(fscanf(arquivo, "%s", "nome") != EOF) {
        if(strcmp(nome, "europe") == 0) {
            printf("Found\n");
        }
    }
    return;
} */

int linhaDisponivel (char nomeArquivo) {
    int cont=0;
    char ch;
    arquivo = fopen(nomeArquivo, "r");

    while (!eof(arquivo)) { /* Enquanto não chegar ao final do arquivo */
        if (ch == '\n') {
            ++cont;
        }
    }
    printf("nome arquivo: %s\n", nomeArquivo);
    printf("Linha disponivel: %d\n",cont); /* imprime o caractere lido */
    return cont;
}
