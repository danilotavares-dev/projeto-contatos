#include <stdio.h>
#include <string.h>

// declarando uma diretiva chamada MAX com o valor 100
#define MAX 100

// Criando uma estrutura chamada Contato para padronizar dados
typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

int main() {

    // declaração de variáveis - tipos: Contato e inteiro
    Contato contatos[MAX];
    int qtd = 0;
    int n;
    int i;

    // perguntando e lendo a quantidade de cadastros a serem informados pelo usuário
    printf("Informe o número de cadastros a serem feitos (max %d): ", MAX);
    if (scanf("%d", &n) != 1)
        return 0;

    // se 'n' for menor que 0 ou maior que 'MAX' o programa encerra...
    if (n < 0 || n > MAX)
        return 0;

    // Enquanto o carácter não for 'Enter' continue lendo...
    while (getchar() != '\n');

    // loop para a coleta de dados do usuário
    for (i = 0; i < n; i++) {
        printf("\n--- Contato %d ---\n", i + 1);

        printf("Nome: ");
        fgets(contatos[i].nome, sizeof(contatos[i].nome), stdin);

        printf("Telefone: ");
        fgets(contatos[i].telefone, sizeof(contatos[i].telefone), stdin);

        printf("E-mail: ");
        fgets(contatos[i].email, sizeof(contatos[i].email), stdin);

        qtd++;
    }

    // Impressão dos valores na tela
    printf("\n--- Lista de Contatos ---\n");

    for (i = 0; i < qtd; i++) {
        printf("\nContato %d:\n", i + 1);
        printf("Nome: %s", contatos[i].nome);
        printf("Telefone: %s", contatos[i].telefone);
        printf("E-mail: %s", contatos[i].email);
    }

    return 0;
}