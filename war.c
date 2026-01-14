#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

/* ---------- FUNÇÕES ---------- */

void cadastrarTerritorios(Territorio *t, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nTerritorio %d\n", i + 1);

        printf("Nome: ");
        scanf("%29s", t[i].nome);

        printf("Cor do exercito: ");
        scanf("%9s", t[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &t[i].tropas);
    }
}

void exibirTerritorios(Territorio *t, int qtd) {
    printf("\n=====================================\n");
    printf("        TERRITORIOS ATUAIS\n");
    printf("=====================================\n");

    for (int i = 0; i < qtd; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i, t[i].nome, t[i].cor, t[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {
    if (atacante->tropas < 2) {
        printf("\nAtaque impossivel! Tropas insuficientes.\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n🎲 Ataque em andamento...\n");
    printf("Atacante (%s) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");

        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;

        strcpy(defensor->cor, atacante->cor);
    } else {
        printf("Defensor resistiu!\n");
        atacante->tropas--;
    }
}

void liberarMemoria(Territorio *t) {
    free(t);
}

/* ---------- MAIN ---------- */

int main() {
    srand(time(NULL));

    int qtd;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &qtd);

    Territorio *territorios = calloc(qtd, sizeof(Territorio));

    if (territorios == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    cadastrarTerritorios(territorios, qtd);

    int opcao;
    do {
        exibirTerritorios(territorios, qtd);

        int a, d;
        printf("\nEscolha o atacante (indice): ");
        scanf("%d", &a);

        printf("Escolha o defensor (indice): ");
        scanf("%d", &d);

        if (a >= 0 && a < qtd && d >= 0 && d < qtd && a != d) {
            atacar(&territorios[a], &territorios[d]);
        } else {
            printf("Escolha invalida!\n");
        }

        printf("\nDeseja realizar outro ataque? (1-Sim / 0-Nao): ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    liberarMemoria(territorios);

    printf("\nMemoria liberada. Jogo encerrado!\n");
    return 0;
}
