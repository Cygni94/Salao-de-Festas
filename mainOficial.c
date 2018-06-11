#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    int codigo;
    char nome[50], endereco[100], telefone[10], dataNasc[9];
} Cliente;

typedef struct Funcionario {
    int codigo;
    char nome[50], telefone[10], funcao[21], salario[10], tipo[5];
} Funcionario;

typedef struct Fornecedor {
    int codigo;
    char nome[50], telefone[10], produto[21];
} Fornecedor;

typedef struct Festa {
    int codigo, codCliente, qConvidados, horario;
    char data[9], diaSemana[15], tema[30];
} Festa;

typedef struct Contrato {
    int codigo, codFesta, valorTotal, desconto, valorFinal;
    char formaPagto[15], status[5];
} Contrato;

int definirCodigo(int);
void cadastroCliente();
void cadastroFesta();
int consultaCodCliente();
int calculoContrato(int, int);
void pesquisa();

FILE *arquivo;

int main() {
    int opcao;
    do {
        printf ("\n ---- SALAO DE FESTAS PATATI PATATA ----\n");
        printf ("\n - Escolha uma opcao abaixo\n");
        printf ("\n - [1] - Cadastrar Cliente");
        printf ("\n - [2] - Cadastrar Funcionario");
        printf ("\n - [3] - Cadastrar Fornecedor");
        printf ("\n - [4] - Cadastrar Festa");
        printf ("\n - [5] - Fazer orcamento");
        printf ("\n - [6] - Atualizar status de contrato");
        printf ("\n - [7] - Pesquisar cadastros");
        printf ("\n - [8] - Exibir festas contratadas");
        printf ("\n - [9] - Pesquisar festas por data");
        printf ("\n - [10] - SAIR\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            cadastroCliente();
            break;
        case 2:
            //pesquisar(CLIENTE, "Rennan");
            break;
        case 3:
            //cadastrarFornecedor();
            break;
        case 4:
            cadastroFesta();
            break;
        case 5:
            //finalizar();
            break;
        case 6:
            //exibirPesquisa();
            break;
        case 10:
            break;
        default:
            printf ("\n Opcao errada...\n");
            break;
        }
    } while (opcao != 10);
    return 0;
}

void cadastroCliente () {
    Cliente Cliente;
    Cliente.codigo = definirCodigo(1);
    arquivo = fopen("clientes.txt","a");

    printf("***** Cadastro de clientes *****\n\n");
    printf("Digite o nome: ");
    gets(Cliente.nome);
    gets(Cliente.nome);
    printf("Digite o endereco: ");
    gets(Cliente.endereco);
    printf("Digite o telefone(apenas numeros, 8 ou 9 digitos): ");
    gets(Cliente.telefone);
    printf("Digite a data de nascimento(apenas numeros): ");
    gets(Cliente.dataNasc);
    fprintf(arquivo, "%d", Cliente.codigo);
    fputs("|",arquivo);
    fputs(Cliente.nome, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.endereco, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.telefone, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.dataNasc, arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);

    printf("O cliente %s foi registrado com sucesso. Codigo do cliente: %d\n", Cliente.nome, Cliente.codigo);
    return ;
}

void cadastroFesta() {
    Festa Festa;
    Festa.codigo = definirCodigo(4);
    arquivo = fopen("festas.txt","a");

    printf("***** Cadastro de festas *****\n\n");
    Festa.codCliente = consultaCodCliente();
    printf("Digite a quantidade de convidados: ");
    gets(Festa.qConvidados);
    printf("Informe a data: ");
/*    Festa.data = agendarFesta(Festa.codCliente);
    printf("Digite a data de nascimento(apenas numeros): ");
    gets(Cliente.dataNasc);
    fprintf(arquivo, "%d", Cliente.codigo);
    fputs("|",arquivo);
    fputs(Cliente.nome, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.endereco, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.telefone, arquivo);
    fputs("|",arquivo);
    fputs(Cliente.dataNasc, arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);

    printf("O cliente %s foi registrado com sucesso. Codigo do cliente: %d\n", Cliente.nome, Cliente.codigo);
    */
    return ;
}

int definirCodigo (int opcao) {
    int contadorLinhas = 0;
    char ch;

    switch(opcao) {
    case 1:
        arquivo = fopen("clientes.txt", "r");
        break;
    case 4:
        arquivo = fopen("festas.txt", "r");
        break;
    }

    while ((ch = getc(arquivo)) != EOF) {
        if (ch == '\n') {
            ++contadorLinhas;
        }
    }
    fclose(arquivo);

    return contadorLinhas;
}

int consultaCodCliente() {
    char ch, nomeCliente[50], comparador[50];
    int i = 0, contadorLinhas = 0, codCliente = 0, tamNome=0;

    printf("Digite o nome do cliente: ");
    gets(nomeCliente);
    gets(nomeCliente);

    tamNome = strlen(nomeCliente);

    printf("tamNome %d\n\n", tamNome);

    arquivo = fopen("clientes.txt", "r");
    while ((ch = getc(arquivo)) != EOF)  {
        if (ch == nomeCliente[i]) {
            comparador[i] = ch;
            i++;
        }
        if (tamNome == i) {
            break;
        } else if (ch == '\n') {
            i=0;
            contadorLinhas++;
        }
    }
    codCliente = contadorLinhas;

    fclose(arquivo);

    return codCliente;
}

int convidados = 30;
int diaSemana = 7;

int calculoContrato (int convidados, int diaSemana) {
int valorTotal = 0;
    switch (convidados) {
    case 30:
        if (diaSemana < 5) {
            valorTotal = 1899;
        } else if (diaSemana >= 5 || diaSemana <=7) {
            valorTotal = 2099;
        }
        break;
    case 50:
        if (diaSemana < 5) {
            valorTotal = 2199;
        } else if (diaSemana >= 5 || diaSemana <=7) {
            valorTotal = 2299;
        }
        break;
    case 80:
        if (diaSemana < 5) {
            valorTotal = 3199;
        } else if (diaSemana >= 5 || diaSemana <=7) {
            valorTotal = 3499;
        }
        break;
    case 100:
        if (diaSemana < 5) {
            valorTotal = 3799;
        } else if (diaSemana >= 5 || diaSemana <=7) {
            valorTotal = 3999;
        }
        break;
    }
}



