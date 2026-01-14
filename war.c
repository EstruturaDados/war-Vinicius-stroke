#include <stdio.h>
#include <string.h>
#include <string.h>
#include <time.h>


typedef struct  {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;


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

int main() {

    
    struct Territorio territorios[5];

    printf("=====================================\n");
    printf("     CADASTRO DE TERRITORIOS\n");
    printf("=====================================\n\n");

   
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf("%29s", territorios[i].nome);

        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);

        printf("Digite o numero de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("-------------------------------------\n");
    }

    /*
        Exibição dos dados cadastrados
    */
    printf("\n=====================================\n");
    printf("   TERRITORIOS CADASTRADOS\n");
    printf("=====================================\n");

    for (int i = 0; i < 5; i++) {
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Numero de tropas: %d\n", territorios[i].tropas);
        printf("-------------------------------------\n");
    }

    return 0;
}
