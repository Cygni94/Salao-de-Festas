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
char agendarFesta();
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
    Festa.data = agendarFesta();
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

/* void pesquisa(int tipoCadastro) {

    int contador = 0;

    char *nomeArquivo;

    Cliente Cliente;

    char dados[1024] = {0};

    switch(tipoCadastro) {
    case 1:
        nomeArquivo = "clientes.txt";
        break;
    case 2:
        nomeArquivo = "funcionario.txt";
        break;
    case 3:
        nomeArquivo = "fornecedor.txt";
        break;
    }

    FILE *arquivo = fopen(nomeArquivo,"r");

    printf("--------Buscando---------\n");

    while(fgets(dados, sizeof(dados), arquivo) != NULL) {
        scanf(dados, "%s\t%[^\t]\t%[^\t]%s\t%s", Cliente.codigo, Cliente.nome, Cliente.endereco, Cliente.telefone, Cliente.dataNasc);
        if(strstr(Cliente.nome, dado) != NULL ) {
            printf("\n");
            printf("Codigo: %s", Cliente.codigo);
            printf("\n");
            printf("Nome: %s", Cliente.nome);
            printf("\n");
            printf("Endereco: %s", Cliente.endereco);
            printf("\n");
            printf("Telefone: %s", Cliente.telefone);
            printf("\n");
            printf("Data de nascimento: %s", Cliente.data);

            contador++;
        }
    }

    printf("\n\nForam encontrados %i registros.\n", contador);
    system("pause");

    fclose(arquivo);
} */

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
