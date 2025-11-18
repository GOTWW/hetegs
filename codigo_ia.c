#include <stdio.h>
#include <string.h>

#define MAX_FUNC 100
#define NUM_PERIODOS 6

typedef struct {
    char nome[50];
    char nivel; // 'J', 'P', 'S'
    float performance[NUM_PERIODOS];
    float media;
    float variacao; // último - penúltimo período
} Funcionario;

void lerFuncionarios(Funcionario funcionarios[], int *qtd) {
    int i, j;
    int n;
    printf("Quantos funcionarios deseja cadastrar (max %d)? ", MAX_FUNC);
    scanf("%d", &n);
    if (n > MAX_FUNC) {
        n = MAX_FUNC;
    }
    *qtd = n;

    for (i = 0; i < n; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", funcionarios[i].nome);
        printf("Nivel (J/P/S): ");
        scanf(" %c", &funcionarios[i].nivel);

        printf("Informe a performance em %d periodos:\n", NUM_PERIODOS);
        for (j = 0; j < NUM_PERIODOS; j++) {
            printf("Periodo %d: ", j + 1);
            scanf("%f", &funcionarios[i].performance[j]);
        }
    }
}

void calcularMetricas(Funcionario funcionarios[], int qtd) {
    int i, j;
    for (i = 0; i < qtd; i++) {
        float soma = 0.0f;
        for (j = 0; j < NUM_PERIODOS; j++) {
            soma += funcionarios[i].performance[j];
        }
        funcionarios[i].media = soma / NUM_PERIODOS;
        if (NUM_PERIODOS >= 2) {
            funcionarios[i].variacao =
                funcionarios[i].performance[NUM_PERIODOS - 1] -
                funcionarios[i].performance[NUM_PERIODOS - 2];
        } else {
            funcionarios[i].variacao = 0.0f;
        }
    }
}

void ordenarPorMedia(Funcionario funcionarios[], int qtd, char nivel) {
    int i, j;
    for (i = 0; i < qtd - 1; i++) {
        for (j = i + 1; j < qtd; j++) {
            if (funcionarios[i].nivel == nivel && funcionarios[j].nivel == nivel) {
                if (funcionarios[j].media > funcionarios[i].media) {
                    Funcionario temp = funcionarios[i];
                    funcionarios[i] = funcionarios[j];
                    funcionarios[j] = temp;
                }
            }
        }
    }
}

void listarPorNivel(Funcionario funcionarios[], int qtd, char nivel) {
    int i, j;
    ordenarPorMedia(funcionarios, qtd, nivel);
    printf("\nFuncionarios do nivel %c ordenados por media de performance:\n", nivel);
    for (i = 0; i < qtd; i++) {
        if (funcionarios[i].nivel == nivel) {
            printf("\nNome: %s\n", funcionarios[i].nome);
            printf("Nivel: %c\n", funcionarios[i].nivel);
            printf("Performance: ");
            for (j = 0; j < NUM_PERIODOS; j++) {
                printf("%.2f ", funcionarios[i].performance[j]);
            }
            printf("\nMedia: %.2f\n", funcionarios[i].media);
            printf("Variacao (ultimo - penultimo): %.2f\n", funcionarios[i].variacao);
        }
    }
}

int buscarFuncionario(Funcionario funcionarios[], int qtd, const char *nome) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (strcmp(funcionarios[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrarFuncionario(Funcionario f) {
    int j;
    printf("\nNome: %s\n", f.nome);
    printf("Nivel: %c\n", f.nivel);
    printf("Performance: ");
    for (j = 0; j < NUM_PERIODOS; j++) {
        printf("%.2f ", f.performance[j]);
    }
    printf("\nMedia: %.2f\n", f.media);
    printf("Variacao (ultimo - penultimo): %.2f\n", f.variacao);
}

int main() {
    Funcionario funcionarios[MAX_FUNC];
    int qtd = 0;
    int opcao;
    char nivel;
    char nomeBusca[50];

    lerFuncionarios(funcionarios, &qtd);
    calcularMetricas(funcionarios, qtd);

    do {
        printf("\n=== Menu Analista de Performance ===\n");
        printf("1 - Listar funcionarios de um nivel\n");
        printf("2 - Buscar funcionario por nome\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o nivel (J/P/S): ");
                scanf(" %c", &nivel);
                listarPorNivel(funcionarios, qtd, nivel);
                break;
            case 2:
                printf("Nome do funcionario: ");
                scanf(" %49[^\n]", nomeBusca);
                {
                    int idx = buscarFuncionario(funcionarios, qtd, nomeBusca);
                    if (idx >= 0) {
                        mostrarFuncionario(funcionarios[idx]);
                    } else {
                        printf("Funcionario nao encontrado.\n");
                    }
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
