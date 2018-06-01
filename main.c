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

int main() {
//    cadastroCliente();
    Pesquisa();
    printf("retornou e fim");
    printf("\n\nddd");
    return 0;
}

void cadastroCliente () {
    FILE *arquivo;
    unsigned long int codigo, telefone, dataNasc;
    char nome[100], endereco[100];
    arquivo = fopen("clientes.txt","a+");
    printf("***** Cadastro de clientes *****\n\n");
    codigo = rand() % 100;
    printf("Digite o nome:");
    gets(nome);
    printf("Digite o endereco:");
    gets(endereco);
    printf("Digite o telefone(apenas numeros, 8 ou 9 digitos): ");
    scanf("%lu", &telefone);
    printf("Digite a data de nascimento(apenas numeros): ");
    scanf("%lu", &dataNasc);
    fprintf(arquivo, "%lu", codigo);
    fputs("|",arquivo);
    fputs(nome, arquivo);
    fputs("|",arquivo);
    fputs(endereco, arquivo);
    fputs("|",arquivo);
    fprintf(arquivo, "%lu", telefone);
    fputs("|",arquivo);
    fprintf(arquivo, "%lu", dataNasc);
    fputs("\n", arquivo);
    fclose(arquivo);
    return;
}

void Pesquisa() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt","r");
    char nome[] = "europe";
    while(fscanf(arquivo, "%s", "nome") != EOF) {
        if(strcmp(nome, "europe") == 0) {
            printf("Found\n");
        }
    }
    return;
}
