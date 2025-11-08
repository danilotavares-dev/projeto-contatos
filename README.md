# PROJETO: AGENDA DE CONTATOS

## 📄 Descrição

Projeto acadêmico para criar um sistema de "Agenda de Contatos" capaz de armazenar e gerenciar dados pessoais (nome, telefone, e-mail). O desenvolvimento é incremental, evoluindo de um cadastro simples para uma aplicação robusta com validação de dados, busca e armazenamento múltiplo usando `structs`, e modularizado em funções.

## 🎯 Objetivo

O objetivo principal é desenvolver um sistema para armazenar e gerenciar contatos pessoais, aplicando conceitos fundamentais de programação de forma incremental, conforme as etapas definidas na disciplina.

## ✨ Funcionalidades

O programa implementa as seguintes operações através de um menu interativo:

* **Adicionar Contato:** Permite cadastrar um novo contato (nome, telefone, e-mail) e armazena em memória.
* **Listar Contatos:** Exibe todos os contatos atualmente cadastrados na agenda.
* **Buscar Contato:** Procura por um contato específico (você pode definir se a busca será por nome, e-mail, etc.).
* **Remover Contato:** Exclui um contato da agenda.
* **Validação de Dados:** Verifica duplicidade ou formato dos dados antes de salvar (ex: se o e-mail já existe).

## 🛠️ Tecnologias Utilizadas

* Linguagem C

## ⚙️ Como Compilar e Executar

1.  Clone este repositório:
    ```bash
    git clone [URL-DO-SEU-REPOSITORIO]
    ```

2.  Navegue até o diretório do projeto:
    ```bash
    cd [NOME-DO-SEU-REPOSITORIO]
    ```

3.  Compile o programa (exemplo usando GCC):
    ```bash
    gcc main.c -o agenda
    ```
    *(**Nota:** Se você separou o código em vários arquivos .c, ajuste o comando, ex: `gcc main.c funcoes.c -o agenda`)*

4.  Execute o programa:
    ```bash
    ./agenda
    ```
