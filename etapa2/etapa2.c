#include <stdio.h>
#include <string.h>

int main() {
    // Declaração de variáveis - tipos: carácter
    char nome[50];
    char telefone[20];
    char email[50];

    printf("--- Cadastro de Contato ---\n");

    // entrada e leitura dos dados informador pelo usuário

    printf("Digite o nome: ");
    if (!fgets(nome, sizeof(nome), stdin))
        return 0;

    printf("Digite o telefone: ");
    if (!fgets(telefone, sizeof(telefone), stdin))
        return 0;

    printf("Digite o email: ");
    if (!fgets(email, sizeof(email), stdin))
        return 0;

    // validação do email informado

    if (strchr(email, '@') == NULL) {
        printf("\nE-mail inválido. Cadastro não realizado.\n");
    }
    else {
        // impressão na tela de todos os dados - caso esteja tudo válido

        printf("\nE-mail válido.\n");
        printf("\n--- Contato Cadastrado ---\n");
        printf("Nome: %s", nome);
        printf("Telefone: %s", telefone);
        printf("E-mail: %s", email);
    }

    return 0;
}