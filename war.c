#include <stdio.h>
#include <string.h>


struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

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
