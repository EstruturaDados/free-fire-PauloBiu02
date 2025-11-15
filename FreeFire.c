#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_NOME 50
#define TAM_TIPO 30

typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("\n=== INVENTARIO BASICO ===\n");
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void adicionarItem() {
    if (numItens >= MAX_ITENS) {
        printf("Erro: Mochila cheia! Maximo %d itens.\n", MAX_ITENS);
        return;
    }
    
    printf("\n--- Adicionar Item ---\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", mochila[numItens].nome);
    limparBuffer();
    
    printf("Tipo: ");
    scanf(" %[^\n]", mochila[numItens].tipo);
    limparBuffer();
    
    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);
    limparBuffer();
    
    numItens++;
    printf("Item adicionado com sucesso!\n");
}

void removerItem() {
    if (numItens == 0) {
        printf("Erro: Mochila vazia!\n");
        return;
    }
    
    printf("\n--- Remover Item ---\n");
    printf("Nome do item a remover: ");
    char nome[TAM_NOME];
    scanf(" %[^\n]", nome);
    limparBuffer();
    
    int encontrado = -1;
    
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado == -1) {
        printf("Item '%s' nao encontrado!\n", nome);
        return;
    }
    
    for (int i = encontrado; i < numItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    
    numItens--;
    printf("Item '%s' removido com sucesso!\n", nome);
}

void listarItens() {
    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    printf("\n--- Itens na Mochila (%d/%d) ---\n", numItens, MAX_ITENS);
    printf("+------------------------------------------------+\n");
    printf("| %-20s | %-15s | %-8s |\n", "NOME", "TIPO", "QTD");
    printf("+------------------------------------------------+\n");
    
    for (int i = 0; i < numItens; i++) {
        printf("| %-20s | %-15s | %-8d |\n", 
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    
    printf("+------------------------------------------------+\n");
}

int main() {
    int opcao;
    
    printf("=== INVENTARIO BASICO ===\n");
    printf("Capacidade maxima: %d itens\n", MAX_ITENS);
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    return 0;
}
