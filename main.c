#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contrato {
    int codigo, codFesta, valorTotal, desconto, valorFinal, formaPagto;
    char status[5];
} Contrato;

int definirCodigo(int);
void cadastroCliente();
void cadastroFesta();
int consultaCodCliente();
void cadastrarContrato();
int calculoContrato(int, int);
int valorFinal(int);
void pesquisa();

int main() {
    cadastrarContrato();
    return 0;
}

void cadastrarContrato() {
Contrato Contrato;
    arquivo = fopen("festas.txt","a+");

    printf("***** Cadastro de contratos *****\n\n");
    printf("Informe o codigo da festa: ");
    gets(Contrato.codFesta);


}

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
    printf("Valor total: %d\n", valorTotal);

    valorFinal(valorTotal);
}

int valorFinal(int valorTotal) {
    double valorFinal = 0, valorParcelas = 0;
    int opcao, numParcelas = 0;

    printf("Selecione a forma de pagamento: \n");
    printf("[1] - A vista\n");
    printf("[2] - Duas vezes\n");
    printf("[3] - Três vezes\n");
    printf("[4] - Quatro ou mais vezes\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        valorFinal = valorTotal*0.9;
        valorParcelas = valorFinal;
        break;
    case 2:
        valorFinal = valorTotal*0.95;
        valorParcelas = valorFinal/2;
        break;
    case 3:
        valorFinal = valorTotal*0.98;
        valorParcelas = valorFinal/3;
        break;
    case 4:
        printf("Informe o numero de parcelas desejado: ");
        scanf("%d", &numParcelas);
        valorFinal = valorTotal;
        valorParcelas = valorFinal/numParcelas;
    }

}

