#include <stdio.h>

int main() {
    // declaração das variaveis do tipo carácter
    char nome[50];
    char telefone[20];
    char email[50];

    printf("--- Cadastro de Contato ---\n");

    // área para o usuário informar os dados

    printf("Digite o nome: ");
    if (!fgets(nome, sizeof(nome), stdin))
        return 0;

    printf("Digite o telefone: ");
    if (!fgets(telefone, sizeof(telefone), stdin))
        return 0;

    printf("Digite o email: ");
    if (!fgets(email, sizeof(email), stdin))
        return 0;

    // imprimir os dados do usuário na tela
    printf("\n--- Contato Cadastrado ---\n");
    printf("Nome: %s", nome);
    printf("Telefone: %s", telefone);
    printf("E-mail: %s", email);

    return 0;
}