#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define CLIENTE 0
#define FUNCIONARIO 1
#define FORNECEDOR 2
#define FESTA 3
#define CONTRATO 4

int jaTeveGets = 0;

void cadastrarCliente();
void cadastrarFuncionario();
void cadastrarFornecedor();
void cadastrarFesta();
/*FILE *cliente;
FILE *funcionario;
FILE *fornecedor;
FILE *festa;*/
typedef struct Cliente
{
    char codigo[100], nome[250], endereco[250], data[15], telefone[30];
}cliente;
typedef struct Funcionario
{
    char codigo[100], telefone[30], nome[250], funcao[250], tipo[10], salario[100];
}funcionario;
typedef struct Fornecedor
{
    char codigo[100], telefone[30], nome[250], produto[250];
}fornecedor;
typedef struct Festa
{
    char codigo[100], quantidade[100], codigoCliente[100], tema[250], diaSemana[40], data[15], inicio[10], terminio[10];
}festa;
//// Main
int main ( )
{
     int op;
     do {
         system("cls");
         printf ("\n ---- MENU CADASTROS ----\n");
         printf ("\n - Escolha uma opcao abaixo\n");
         printf ("\n - [1] - Cadastrar Cliente: ");
         printf ("\n - [2] - Cadastrar Funcionario: ");
         printf ("\n - [3] - Cadastrar Fornecer: ");
         printf ("\n - [4] - Cadastrar Festa: ");
         printf ("\n - [5] - SAIR\n");
         printf("\n - [6] - PESQUISA\n");
         scanf("%d", &op);
         switch (op)
            {
              case 1:
                   cadastrarCliente();
                   break;
              case 2:
                   cadastrarFuncionario();
                   break;
              case 3:
                   cadastrarFornecedor();
                   break;
              case 4:
                   cadastrarFesta();
                   break;
              case 5:
                    finalizar();
                    break;
              case 6:
                    exibirPesquisa();
                    break;
              default:
                   printf ("\n Opcao errada...\n");
                   break;
            }
     }while (op != 0);
     finalizar();
     return 0;
}
/////// Funcoes
void receberDados(char *dado)
{
    if(jaTeveGets == 0)
    {
        gets(dado);
        gets(dado);
        jaTeveGets = 1;
    }
    else
    {
        gets(dado);
    }
}
void pesquisar(int tipo, char *dado)
{
    int contador = 0;
    char *nomeArquivo;
    cliente Cliente;
    char dados[1024] = {0};

    switch(tipo){
        case CLIENTE:
            nomeArquivo = "clientes.txt";
            break;
        case FUNCIONARIO:
            nomeArquivo = "funcionario.txt";
            break;
        case FORNECEDOR:
            nomeArquivo = "fornecedor.txt";
            break;
        case FESTA:
            nomeArquivo = "festa.txt";
            break;
    }
    FILE *arquivo = fopen(nomeArquivo,"r");
    system("cls");
    printf("--------Buscando---------\n");
    while(fgets(dados, sizeof(dados), arquivo) != NULL)
    {
        sscanf(dados, "%s\t%[^\t]\t%[^\t]%s\t%s", Cliente.codigo, Cliente.nome, Cliente.endereco, Cliente.telefone, Cliente.data);
        if(strstr(Cliente.nome, dado) != NULL )
        {
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
}
void exibirPesquisa()
{
    char dados[1024] = {0};
    int op = -1;
    jaTeveGets = 0;
    system("cls");
    printf("\n ------ Busca de Dados -------");
    printf("\n Escolha a opcao: \n");
    printf("\n [0] - CLIENTE \n");
    printf("\n [1] - FUNCIONARIO \n");
    printf("\n [2] - FORNECEDOR \n");
    printf("\nOpcao: ");
    scanf("%i", &op);
    system("cls");
    printf("\n ------ Busca de Dados -------");
    printf("\n Pesquisar: ");
    receberDados(dados);
    pesquisar(op, dados);
}

//Exibir saida
void exibirMenuSaida(int tipo)
{
     int op;
     do {
         system ("cls");
         printf ("\n ---- Escolha uma opcao abaixo ----\n");
         printf ("\n - [1] - SAIR");
         if(tipo == CLIENTE)
         {
            printf("\n - [2] - CONTINUAR COM OS CADASTROS DE CLIENTES ");
         }
         else if( tipo == FUNCIONARIO)
         {
            printf("\n - [2] - CONTINUAR COM OS CADASTROS DE FUNCIONARIO ");
         }
         else if( tipo == FORNECEDOR)
         {
            printf("\n - [2] - CONTINUAR COM OS CADASTROS DE FORNECEDOR ");
         }
         else if( tipo == FESTA)
         {
            printf("\n - [2] - CONTINUAR COM OS CADASTROS DE FESTA ");
         }
         else if( tipo == CONTRATO)
         {
            printf("\n - [2] - CONTINUAR COM OS CADASTROS DE CONTRATO ");
         }
         printf ("\n - [3] - VOLTA AO MENU PRINCIPAL\n");
         scanf (" %d",&op);
         system ("cls");
         switch (op)
         {
              case 1:
                   finalizar();
                   break;
              case 2:
                     if(tipo == CLIENTE)
                     {
                        cadastrarCliente();
                        return;
                     }
                     else if( tipo == FUNCIONARIO)
                     {
                        cadastrarFuncionario();
                        return;
                     }
                     else if( tipo == FORNECEDOR)
                     {
                        cadastrarFornecedor();
                        return;
                     }
                     else if( tipo == FESTA)
                     {
                        cadastrarFesta();
                        return;
                     }
                     else if( tipo == CONTRATO)
                     {
                        return 1;
                     }
                    break;
              case 3:
                   return 1;
                   break;
              default:
                   printf ("\n Opcao errado...\n");
                   break;
         }
     }while (op != 0);
     return (0);
}
void cadastrarCliente()
{
    cliente Cliente;
    int op = -1;
    char dados[1024] = {0};
    jaTeveGets = 0;
    system ("cls");
    printf("\n ------ Cadastro de Cliente -------");
    strcpy(Cliente.codigo,"1");
    printf("\n\n");
    printf("Nome: ");
    receberDados(Cliente.nome);
    printf("\n");
    printf("Endereco: ");
    receberDados(Cliente.endereco);
    printf("\n");
    printf("Telefone: ");
    receberDados(Cliente.telefone);
    printf("\n");
    printf("Data de nascimento: ");
    receberDados(Cliente.data);
    printf("\n");
    sprintf(dados, "%s\t%s\t%s\t%s\t%s\n", Cliente.codigo, Cliente.nome, Cliente.endereco, Cliente.telefone, Cliente.data);
    printf("Deseja salvar o registro? [[1]-SIM/[2]-NAO]\n");
    scanf("%d",&op);
    if(op == 1)
    {
       gravarArquivo(CLIENTE, dados);
    }
    exibirMenuSaida(CLIENTE);
}
void cadastrarFuncionario()
{
    funcionario Funcionario;
    int op = -1;
    char dados[1024] = {0};
    jaTeveGets = 0;
    system ("cls");
    printf("\n ------ Cadastro de Funcionario -------");
    strcpy(Funcionario.codigo, "1");
    printf("\n Nome: ");
    receberDados(Funcionario.nome);
    printf("\n Funcao: ");
    receberDados(Funcionario.funcao);
    printf("\n Telefone: ");
    receberDados(Funcionario.telefone);
    printf("\n Salario: ");
    receberDados(Funcionario.salario);
    printf("\n Tipo \(fixo ou temporario): ");
    receberDados(Funcionario.tipo);
    printf("\n");
    sprintf(dados, "%s\t%s\t%s\t%s\t%s\t%s\n", Funcionario.codigo, Funcionario.nome, Funcionario.funcao, Funcionario.telefone, Funcionario.salario, Funcionario.tipo);
    printf("Deseja salvar o registro? [[1]-SIM/[2]-NAO]\n");
    scanf("%d",&op);
    if(op == 1)
    {
       gravarArquivo(FUNCIONARIO, dados);
    }
    exibirMenuSaida(FUNCIONARIO);
}
void cadastrarFornecedor()
{
    fornecedor Fornecedor;
    int op = -1;
    char dados[1024] = {0};
    jaTeveGets = 0;
    system ("cls");
    printf("\n ------ Cadastro de Fornecedor -------");
    strcpy(Fornecedor.codigo, "1");
    printf("\n");
    printf("\n Nome: ");
    receberDados(Fornecedor.telefone);
    //pesquisa(nome);
    printf("\n");
    printf("\n telefone: ");
    receberDados(Fornecedor.telefone);
    printf("\n");
    printf("\n Produto Fornecido: ");
    receberDados(Fornecedor.produto);
    printf("\n");
    sprintf(dados, "%s\t%s\t%s\t%s\n", Fornecedor.codigo, Fornecedor.nome, Fornecedor.telefone, Fornecedor.produto);
    printf("Deseja salvar o registro? [[1]-SIM/[2]-NAO]\n");
    scanf("%d",&op);
    if(op == 1)
    {
       gravarArquivo(FORNECEDOR, dados);
    }
    exibirMenuSaida(FORNECEDOR);
}
void cadastrarFesta()
{
    festa Festa;
    int op = -1;
    char dados[1024] = {0};
    jaTeveGets = 0;
    system ("cls");
    printf("\n ------ Cadastro de Festa -------");
    printf("\n codigo: ");
    strcpy(Festa.codigo, "1");
    printf("\n");
    printf("\n Quantidade de convidados: ");
    receberDados(Festa.quantidade);
    printf("\n");
    printf("\n data: ");
    receberDados(Festa.data);
    printf("\n");
    printf("\n dia da semana: ");
    receberDados(Festa.diaSemana);
    printf("\n");
    printf("\n horario da festa: ");
    printf("\n Horario de inicio: ");
    receberDados(Festa.inicio);
    printf("\n Horario de Terminio: ");
    receberDados(Festa.terminio);
    printf("\n");
    printf("\n tema da festa: ");
    receberDados(Festa.tema);
    printf("\n");
    sprintf(dados, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", Festa.codigo, Festa.quantidade, Festa.data, Festa.diaSemana, Festa.inicio, Festa.terminio, Festa.tema);
    printf("Deseja salvar o registro? [[1]-SIM/[2]-NAO]\n");
    scanf("%d",&op);
    if(op == 1)
    {
       gravarArquivo(FESTA, dados);
    }
    exibirMenuSaida(FESTA);
}
//Tratamento de dados
void gravarArquivo(int tipo, char *dados){

    char *nomeArquivo;

    switch(tipo){
        case CLIENTE:
            nomeArquivo = "clientes.txt";
            break;
        case FUNCIONARIO:
            nomeArquivo = "funcionario.txt";
            break;
        case FORNECEDOR:
            nomeArquivo = "fornecedor.txt";
            break;
    }

    FILE *arquivo = fopen(nomeArquivo,"a+");
    fputs(dados, arquivo);
    fclose(arquivo);
    printf("\n%s\n", "Cadastro efetuado com sucesso.");
    system("pause");
}

/*void leArquivo(char[] nomeArquivo, char[] dados){
   FILE *arquivo1 = fopen("clientes.txt","a+");
}*/

/// Finalizar Programa
void finalizar ()
{
     system ("cls");
     printf ("\n ----- OPERACAO FINALIZADA DO SISTEMA SAlAO DE FESTAS PATATI PATATA -----");
     printf("\n\n\n\n");
     exit (0);
}

