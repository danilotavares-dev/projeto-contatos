#include <stdio.h>
#include <string.h>

int main() {

    // Declaração de variáveis - tipos: inteiro e vetores de carácteres
    int n, i, encontrado = 0;
    char nome[50][50], telefone[50][20], email[50][50];
    char busca[50];

    // Perguntando e lendo quantos cadastros vão ser feitos pelo usuário
    printf("Informe o número de pessoas que deseja cadastrar: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) {
        printf("Número inválido.\n");
        return 0;
    }

    // Enquanto o carácter lido não for 'Enter' continue...
    while (getchar() != '\n'); 

    // Loop para a coleta de dados informada pelo usuário
    for (i = 0; i < n; i++) {
        printf("\n--- Contato %d ---\n", i + 1);

        printf("Nome: ");
        fgets(nome[i], sizeof(nome[i]), stdin);
        nome[i][strcspn(nome[i], "\n")] = '\0';

        printf("Telefone: ");
        fgets(telefone[i], sizeof(telefone[i]), stdin);
        telefone[i][strcspn(telefone[i], "\n")] = '\0';

        printf("E-mail: ");
        fgets(email[i], sizeof(email[i]), stdin);
        email[i][strcspn(email[i], "\n")] = '\0';
    }

    // Listando cada contato
    printf("\n===== LISTA DE CONTATOS =====\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s - %s - %s\n", i + 1, nome[i], telefone[i], email[i]);
    }
    
    // Perguntando o nome de busca dentro agenda
    printf("\nDigite o nome que deseja buscar: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    printf("\nBuscando por '%s'...\n", busca);

    // Loop para a busca do nome na agenda
    for (i = 0; i < n; i++) {
        if (strstr(nome[i], busca)) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\nTelefone: %s\nE-mail: %s\n", nome[i], telefone[i], email[i]);
            encontrado = 1;
        }
    }

    // Caso nenhum contato foi encontrado...
    if (!encontrado)
        printf("Contato não encontrado.\n");

    printf("\nCadastro concluído.\n");

    return 0;
}