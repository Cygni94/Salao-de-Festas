int consultaCodCliente() {
    char ch, nomeCliente[50], comparador[50];
    int i = 0, contadorLinhas = 0, codCliente = 0;

    printf("Digite o nome do cliente: ");
    gets(nomeCliente);
    gets(nomeCliente);

    arquivo = fopen("clientes.txt", "r");
    while ((ch = getc(arquivo)) != EOF)  {
        if (ch == '\n') {
            ++contadorLinhas;
            i = 0;
        } else if (ch == nomeCliente[i]) {
            printf("\nnc %d", i);
            i++;
            if (comparador[i] == nomeCliente[i]) {
                codCliente = contadorLinhas;
            }
        } else {
            printf("Cliente nao encontrado.\n");
        }
    }

    printf("\n cod cliente: %d \n",codCliente);

    fclose(arquivo);

    return codCliente;
}