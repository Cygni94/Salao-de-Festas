    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct Cliente {
        int codigo, telefone, dataNasc;
        char nome[50], endereco[100];
    } Cliente;

    void cadastroCliente();

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
            cadastroCliente();
            break;
        }
        return 0;
    }

    void cadastroCliente () {
        FILE *arquivo;
        arquivo = fopen("clientes.txt","w");
        int codigo, telefone, dataNasc;
        char nome[50], endereco[100];

        printf("***** Cadastro de clientes *****\n\n");
        printf("Digite o nome do cliente ");
        gets(nome);
        gets(nome);
        fputs(nome, arquivo);
        fputs("|",arquivo);
        fflush(stdin);
        printf("Digite o endereco do cliente: ");
        gets(endereco);
        fputs(endereco, arquivo);
        fputs("|",arquivo);
        fflush(stdin);
        printf("Digite o telefone do cliente: ");
        gets(telefone);
        fputs(telefone, arquivo);
        fputs("|",arquivo);
        fflush(stdin);
        printf("Digite a data de nascimento do cliente: ");
        gets(dataNasc);
        fputs(dataNasc, arquivo);
        fputs("|",arquivo);
        fflush(stdin);
        fputs("\n", arquivo);
        fclose(arquivo);
        return;
    }
