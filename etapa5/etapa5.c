#include <stdio.h>
#include <string.h>

// Declaração das diretivas para valores pré definidos.
#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TEL 20
#define TAM_EMAIL 50

// Criação de uma estrutura para padronizar cada dado informado pelo usuário.
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
    char email[TAM_EMAIL];
} Contato;

// declaracão de variáveis = tipos Contato e inteiro.
Contato agenda[MAX_CONTATOS];
int qtd = 0;

// Criação de uma função 'void' chamada trim_newline que remove o 'Enter' pego pelo fgets().
void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

// Criação de uma função do tipo 'inteiro' que faz a validação do email do usuário.
int validar_email(const char *email) {
    const char *at = strchr(email, '@');
    if (!at)
        return 0;

    const char *dot = strchr(at + 1, '.');
    if (!dot)
        return 0;

    if (at == email)
        return 0;

    return 1;
}

// Criação de uma função do tipo 'inteiro' que analisa se tem valores duplicados nos dados informados pelo usuário.
int existe_duplicado(const char *nome, const char *email) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(agenda[i].nome, nome) == 0)
            return 1;

        if (strcmp(agenda[i].email, email) == 0)
            return 1;
    }

    return 0;
}

// Criaçaõ de uma função do tipo 'void' para adicionar novos contatos na agenda.
void adicionarContato() {
    if (qtd >= MAX_CONTATOS) {
        printf("Agenda cheia.\n");
        return;
    }
    Contato c;

    printf("\nNome: ");
    if (!fgets(c.nome, sizeof(c.nome), stdin))
        return;
    trim_newline(c.nome);

    printf("Telefone: ");
    if (!fgets(c.telefone, sizeof(c.telefone), stdin))
        return;
    trim_newline(c.telefone);

    printf("E-mail: ");
    if (!fgets(c.email, sizeof(c.email), stdin))
        return;
    trim_newline(c.email);

    if (!validar_email(c.email)) {
        printf("E-mail inválido. Operação cancelada.\n");
        return;
    }

    if (existe_duplicado(c.nome, c.email)) {
        printf("Contato duplicado. Operação cancelada.\n");
        return;
    }

    agenda[qtd++] = c;
    printf("Contato adicionado.\n");
}

// Criaçaõ de uma função do tipo 'void' para listar o contatos que esta salvos na agenda.
void listarContatos() {
    printf("\n--- Lista de Contatos ---\n");
    if (qtd == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n%d) Nome: %s\n   Telefone: %s\n   E-mail: %s\n", i + 1, agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
}

// Criaçaõ de uma função do tipo 'void' para buscar um determinado contato da agenda através do nome.
void buscarContato() {
    char termo[TAM_NOME];

    printf("\nDigite o nome (ou parte) para buscar: ");
    if (!fgets(termo, sizeof(termo), stdin))
        return;

    trim_newline(termo);
    if (strlen(termo) == 0) {
        printf("Termo vazio.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        if (strstr(agenda[i].nome, termo) != NULL) {
            printf("\nEncontrado:\n%d) Nome: %s\n   Telefone: %s\n   E-mail: %s\n", i + 1, agenda[i].nome, agenda[i].telefone, agenda[i].email);
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

// Criaçaõ de uma função do tipo 'void' para remover um contato da agenda através do número na fila.
void removerContato() {
    if (qtd == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    listarContatos();

    printf("\nDigite o número do contato a remover (0 cancelar): ");
    int num;
    if (scanf("%d", &num) != 1) {
        while (getchar() != '\n')
            ;
        printf("Entrada inválida.\n");
        return;
    }
    while (getchar() != '\n')
        ;
    if (num == 0) {
        printf("Cancelado.\n");
        return;
    }

    if (num < 1 || num > qtd) {
        printf("Número inválido.\n");
        return;
    }

    int idx = num - 1;

    for (int i = idx; i < qtd - 1; i++)
        agenda[i] = agenda[i + 1];

    qtd--;
    printf("Removido.\n");
}

int main() {
    // declaração da variável do tipo inteiro para o usuário escolher qual opção do menu ele deseja realizar.
    int opcao;

    do {
        // menu interativo do programa
        printf("\n--- MENU ---\n1. Adicionar contato\n2. Listar contatos\n3. Buscar contato por nome\n4. Remover contato\n0. Sair\nEscolha: ");
        
        // se o valor informado não estiver no menu, o programa gera uma mensagem de 'Entrada inválida'.
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida.\n");
            continue;
        }

        // Enquanto o carácter lido não for 'Enter', continue lendo.
        while (getchar() != '\n');

        switch (opcao) {
        case 1:
            adicionarContato();
            break;
        case 2:
            listarContatos();
            break;
        case 3:
            buscarContato();
            break;
        case 4:
            removerContato();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}