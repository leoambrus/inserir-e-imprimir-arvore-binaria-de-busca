#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    int chave;
    struct No* esq;
    struct No* dir;
};

struct No* criarNo(int chave) {
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

struct No* inserir(struct No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave);
    }

    return raiz;
}

void nivelTraversal(struct No* raiz) {
    if (raiz == NULL) {
        return;
    }

    // Usando uma fila para realizar a travessia em largura
    struct No* fila[1000];
    int frente = 0;
    int tras = 0;

    fila[tras++] = raiz;

    while (frente < tras) {
        struct No* noAtual = fila[frente++];
        printf("%d ", noAtual->chave);

        if (noAtual->esq != NULL) {
            fila[tras++] = noAtual->esq;
        }

        if (noAtual->dir != NULL) {
            fila[tras++] = noAtual->dir;
        }
    }
}

int main() {
    int valor;
    struct No* raiz = NULL;
    char entrada[10];



    while (scanf("%s", entrada) != EOF) { 

        if (strcmp(entrada, "q") == 0) {
            break; // Encerra o programa se a entrada for "q"
        } else if (strcmp(entrada, "p") == 0) {
            nivelTraversal(raiz);
            printf("\n");
        } else if (strcmp(entrada, "i") == 0) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
    }

    return 0;
}
