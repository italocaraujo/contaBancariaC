#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"portuguese");
	
     char nome[50];
    char tipoConta[] = "Corrente";
    double saldo = 1599.99;
    int opcao = 0;
    
    printf("Qual seu nome?\n");
    fgets(nome, 50, stdin);
	
	if (nome[strlen(nome) - 1] == '\n')
        nome[strlen(nome) - 1] = '\0';
	
    printf("***********************\n");
    printf("\nNome do cliente: %s\n", nome);
    printf("Tipo conta: %s\n", tipoConta);
    printf("Saldo atual: %.2f\n", saldo);
    printf("\n***********************\n");

    printf("\n** Digite sua opção **\n");
    printf("1 - Consultar saldo\n");
    printf("2 - Transferir valor\n");
    printf("3 - Receber valor\n");
    printf("4 - Sair\n");

    while (opcao != 4) {
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("O saldo atualizado é %.2f\n", saldo);
        } else if (opcao == 2) {
            printf("Qual o valor que deseja transferir? ");
            double valor;
            scanf("%lf", &valor);
            if (valor > saldo) {
                printf("Não há saldo para realizar a transferência.\n");
            } else {
                saldo -= valor;
                printf("Novo saldo: %.2f\n", saldo);
            }
        } else if (opcao == 3) {
            printf("Valor recebido: ");
            double valor;
            scanf("%lf", &valor);
            saldo += valor;
            printf("Novo saldo: %.2f\n", saldo);
        } else if (opcao != 4) {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}