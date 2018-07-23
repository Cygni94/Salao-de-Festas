#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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
typedef struct RetornoBusca
{
    char codigo[100], nome[250];
} retornoBusca;
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
/// Main
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
         printf("\n - [6] - Pesquisa\n");
         printf("\n - [7] - Relatorio Cliente \n");
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
              case 7:
                    relatorioCliente();
                    break;
              default:
                   printf ("\n Opcao errada...\n");
                   break;
            }
     }while (op != 0);
     finalizar();
     return 0;
}

int retornaProximoRegistro()
{
    int retorno = 0;
    char dados[32] = {0};
    FILE *arquivo = fopen("contador.txt","r+");
    if(arquivo == NULL)
    {
        arquivo = fopen("contador.txt","w+");
        fputs("0", arquivo);
    }
    else
    {
        fgets(dados, sizeof(dados), arquivo);
        retorno = atoi(dados);
        retorno++;
        fclose(arquivo);
        arquivo = fopen("contador.txt","w+");
        itoa(retorno,dados,10);
        fputs(dados, arquivo);
    }
    fclose(arquivo);
    return retorno;
}
/// Funcoes
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
float calcularValorFesta(char *convidados, char* dia)
{
    float valor = 0.0f;
    int quantidadeConvidados = atoi(convidados);
    int diaDaSemana = atoi(dia);

    if(diaDaSemana < 4)
    {
        if(quantidadeConvidados <= 30)
        {
            valor = 1899.00;
        }
        else if(quantidadeConvidados > 30 && quantidadeConvidados <= 50)
        {
            valor = 2199.00;
        }
        else if(quantidadeConvidados > 50 && quantidadeConvidados <= 80)
        {
            valor = 3199.00;
        }
        else if(quantidadeConvidados > 80 && quantidadeConvidados <= 100)
        {
            valor = 3799.00;
        }
    }
    else
    {
        if(quantidadeConvidados <= 30)
        {
            valor = 2099.00;
        }
        else if(quantidadeConvidados > 30 && quantidadeConvidados <= 50)
        {
            valor = 2299.00;
        } else if(quantidadeConvidados > 50 && quantidadeConvidados <= 80)
        {
            valor = 3499.00;
        }
        else if(quantidadeConvidados > 80 && quantidadeConvidados <= 100)
        {
            valor = 3999.00;
        }
    }
    return valor;
}
retornoBusca pesquisar(int tipo, char *dado, int exibeResultado)
{
    int contador = 0;
    char *nomeArquivo;
    cliente Cliente;
    fornecedor Fornecedor;
    funcionario Funcionario;
    festa Festa;
    char dados[1024] = {0};
    retornoBusca Retorno;

    switch(tipo)
    {
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
    printf("-------- Buscando ---------\n");
    while(fgets(dados, sizeof(dados), arquivo) != NULL)
    {
        if(tipo == CLIENTE)
        {
            sscanf(dados, "%s\t%[^\t]\t%[^\t]%s\t%s", Cliente.codigo, Cliente.nome, Cliente.endereco, Cliente.telefone, Cliente.data);
            if(strstr(Cliente.nome, dado) != NULL)
            {
                if(exibeResultado == 1)
                {
                    printf("\n");
                    printf(" Codigo: %s", Cliente.codigo);
                    printf("\n");
                    printf(" Nome: %s", Cliente.nome);
                    printf("\n");
                    printf(" Endereco: %s", Cliente.endereco);
                    printf("\n");
                    printf(" Telefone: %s", Cliente.telefone);
                    printf("\n");
                    printf(" Data de nascimento: %s", Cliente.data);
                }
                strcpy(Retorno.nome, Cliente.nome);
                strcpy(Retorno.codigo, Cliente.codigo);
                contador++;
            }
        }
        else if(tipo == FUNCIONARIO)
        {
            sscanf(dados, "%s\t%s\t%s\t%s\t%s\t%s\n", Funcionario.codigo, Funcionario.nome, Funcionario.funcao, Funcionario.telefone, Funcionario.salario, Funcionario.tipo);
            if(strstr(Funcionario.nome, dado) != NULL)
            {
                if(exibeResultado == 1)
                {
                    printf("\n");
                    printf(" Codigo: %s", Funcionario.codigo);
                    printf("\n");
                    printf(" Nome: %s", Funcionario.nome);
                    printf("\n");
                    printf(" Funcao: %s", Funcionario.funcao);
                    printf("\n");
                    printf(" Telefone: %s", Funcionario.telefone);
                    printf("\n");
                    printf(" Salario: %s", Funcionario.salario);
                    printf("\n");
                    printf(" Tipo: %s", Funcionario.tipo);
                }
                strcpy(Retorno.nome, Funcionario.nome);
                strcpy(Retorno.codigo, Funcionario.codigo);
                contador++;
            }
        }
        else if(tipo == FORNECEDOR)
        {
            sscanf(dados, "%s\t%s\t%s\t%s\n", Fornecedor.codigo, Fornecedor.nome, Fornecedor.telefone, Fornecedor.produto);
            if(strstr(Fornecedor.nome, dado) != NULL)
            {
                if(exibeResultado == 1)
                {
                    printf("\n");
                    printf(" Codigo: %s", Fornecedor.codigo);
                    printf("\n");
                    printf(" Nome: %s", Fornecedor.nome);
                    printf("\n");
                    printf(" Telefone: %s", Fornecedor.telefone);
                    printf("\n");
                    printf(" Produto: %s", Fornecedor.produto);
                }
                strcpy(Retorno.nome, Fornecedor.nome);
                strcpy(Retorno.codigo, Fornecedor.codigo);
                contador++;
            }
        }
        else if(tipo == FESTA)
        {
            sscanf(dados, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", Festa.codigo, Festa.codigoCliente, Festa.quantidade, Festa.data, Festa.diaSemana, Festa.inicio, Festa.terminio, Festa.tema);
            if(strstr(Festa.codigoCliente, dado) != NULL)
            {
                float valorFesta = calcularValorFesta(Festa.quantidade, Festa.diaSemana);
                if(exibeResultado == 1)
                {
                    printf("\n");
                    printf("\n");
                    printf(" Codigo: %s", Festa.codigo);
                    printf("\n");
                    printf(" Quantidade de convidados: %s", Festa.quantidade);
                    printf("\n");
                    printf(" Data: %s", Festa.data);
                    printf("\n");
                    printf(" Dia da semana: %s", Festa.diaSemana);
                    printf("\n");
                    printf(" Horario de inicio da festa: %s", Festa.inicio);
                    printf("\n");
                    printf(" Horario de termino da festa: %s", Festa.terminio);
                    printf("\n");
                    printf(" Tema da festa: %s", Festa.tema);
                    printf("\n\n");
                    printf("----- Formas de pagamento: --------");
                    printf("\n");
                    printf(" A vista: %.2f", (valorFesta - (valorFesta * 0.1)));
                    printf("\n");
                    printf(" Duas vezes: %.2f", valorFesta - (valorFesta * 0.05));
                    printf("\n");
                    printf(" Tres vezes: %.2f", valorFesta - (valorFesta * 0.02));
                    printf("\n");
                    printf(" Quatro ou mais vezes: %.2f", valorFesta);
                }
                strcpy(Retorno.nome, Festa.tema);
                strcpy(Retorno.codigo, Festa.codigo);
                contador++;
            }
        }
    }
    fclose(arquivo);
    if(contador == 0)
    {
        strcpy(Retorno.nome, "");
    }
    if(exibeResultado == 1)
    {
        printf("\n\nForam encontrados %i registros.\n\n", contador);
        system("pause");
    }
    return Retorno;
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
    pesquisar(op, dados, 1);
}
/// Exibir saida
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
    printf("\n");
    itoa(retornaProximoRegistro(), Cliente.codigo, 10);
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
    itoa(retornaProximoRegistro(), Funcionario.codigo, 10);
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
    char dados[1024] = {'\0'};
    jaTeveGets = 0;
    system ("cls");
    printf("\n ------ Cadastro de Fornecedor -------");
    itoa(retornaProximoRegistro(), Fornecedor.codigo, 10);
    printf("\n");
    printf("\n Nome: ");
    receberDados(Fornecedor.nome);
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
    retornoBusca Retorno;
    festa Festa;
    int clienteEncontrado = 0;
    int op = -1;
    char dados[1024] = {0};
    char nomeUsuario[1024] = {'\0'};
    jaTeveGets = 0;
    while(clienteEncontrado == 0){
        system ("cls");
        printf("\n ------ Cadastro de Festa -------");
        printf("\n");
        printf("\n Digite o nome do Cliente: ");
        receberDados(dados);
        Retorno = pesquisar(CLIENTE, dados, 0);
        printf("encontrou %s", nomeUsuario);
        if(!(strcmp(Retorno.nome, "") == 0))
            clienteEncontrado = 1;
    }
    system ("cls");
    printf("\n ------ Cadastro de Festa -------");
    printf("\n");
    printf("\n Nome do Cliente: %s", Retorno.nome);
    strcpy(Festa.codigoCliente,Retorno.codigo);
    itoa(retornaProximoRegistro(), Festa.codigo, 10);
    printf("\n");
    printf("\n Quantidade de convidados: ");
    receberDados(Festa.quantidade);
    printf("\n");
    printf("\n data: ");
    receberDados(Festa.data);
    printf("\n");
    printf("\n dia da semana: ");
    printf("\n [0] - SEGUNDA, [1] - TERCA, [2] - QUARTA, [3] - QUINTA, [4] - SEXTA, [5] - SABADO, [6] - DOMINGO\n ");
    receberDados(Festa.diaSemana);
    printf("\n");
    printf("\n ---- Horario da festa ---- ");
    printf("\n Horario de inicio: ");
    receberDados(Festa.inicio);
    printf("\n Horario de Terminio: ");
    receberDados(Festa.terminio);
    printf("\n");
    printf("\n tema da festa: ");
    receberDados(Festa.tema);
    printf("\n");
    sprintf(dados, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", Festa.codigo, Festa.codigoCliente, Festa.quantidade, Festa.data, Festa.diaSemana, Festa.inicio, Festa.terminio, Festa.tema);
    printf("Deseja salvar o registro? [[1]-SIM/[2]-NAO]\n");
    scanf("%d",&op);
    if(op == 1)
    {
       gravarArquivo(FESTA, dados);
    }
    exibirMenuSaida(FESTA);
}
void relatorioCliente(){
    retornoBusca Retorno;
    festa Festa;
    int clienteEncontrado = 0;
    int op = -1;
    char dados[1024] = {0};
    char nomeUsuario[1024] = {'\0'};
    jaTeveGets = 0;
    while(clienteEncontrado == 0){
        system ("cls");
        printf("\n ------ Relatorio -------");
        printf("\n");
        printf("Digite 0 para sair");
        printf("\n");
        printf("\n Digite o nome do Cliente: ");
        receberDados(dados);
        if(strcmp(dados,"0") == 0)
            return;
        Retorno = pesquisar(CLIENTE, dados, 0);
        if(!(strcmp(Retorno.nome, "") == 0))
            clienteEncontrado = 1;
    }

    pesquisar(FESTA, Retorno.codigo, 1);
}
/// Tratamento de dados
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
        case FESTA:
            nomeArquivo = "festa.txt";
            break;
    }
    FILE *arquivo = fopen(nomeArquivo,"a+");
    fputs(dados, arquivo);
    fclose(arquivo);
    printf("\n%s\n", "Cadastro efetuado com sucesso.");
    system("pause");
}
/// Finalizar Programa
void finalizar ()
{
     system ("cls");
     printf ("\n ----- OPERACAO FINALIZADA DO SISTEMA SAlAO DE FESTAS PATATI PATATA -----");
     printf("\n\n\n\n");
     exit (0);
}
