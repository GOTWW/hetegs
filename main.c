#include <stdio.h>
#include <string.h>
#include "performance.h"
#include <ctype.h>

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta */
    }
}

void lerLinha(char *str, int tamanho) {
    if (fgets(str, tamanho, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }
}

void cadastrarFuncionarios(TimeTI *time) {
    int n, i, j;
    Funcionario f;

    printf("Quantos funcionarios deseja cadastrar (max %d)? ", MAX_FUNC);
    scanf("%d", &n);
    limparEntrada();

    if (n > MAX_FUNC) {
        n = MAX_FUNC;
    }

    for (i = 0; i < n; i++) {
        printf("\n=== Cadastro do funcionario %d ===\n", i + 1);

        printf("Nome: ");
        lerLinha(f.nome, sizeof(f.nome));

        do {
            printf("Nivel (J - junior, P - pleno, S - senior): ");
            scanf(" %c", &f.nivel);
            f.nivel = (char) toupper((unsigned char) f.nivel);
            limparEntrada();
        } while (f.nivel != 'J' && f.nivel != 'P' && f.nivel != 'S');

        printf("Informe a performance em %d periodos (ex: sprints ou meses):\n",
               NUM_PERIODOS);
        for (j = 0; j < NUM_PERIODOS; j++) {
            printf("Periodo %d: ", j + 1);
            scanf("%f", &f.performance[j]);
            limparEntrada();
        }

        calcularMetricasFuncionario(&f);
        adicionarFuncionario(time, f);
    }
}

int main() {
    TimeTI time;
    int opcao;
    char nivel;
    char nomeBusca[50];

    inicializarTime(&time);

    printf("=== Sistema Analista de Performance de TI ===\n");
    cadastrarFuncionarios(&time);
    calcularMetricasTime(&time);

    do {
        printf("\n=== Menu ===\n");
        printf("1 - Listar funcionarios de um nivel ordenados por media\n");
        printf("2 - Buscar funcionario por nome\n");
        printf("3 - Mostrar quedas de performance recente por nivel\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparEntrada();

        switch (opcao) {
            case 1:
                printf("Informe o nivel (J/P/S): ");
                scanf(" %c", &nivel);
                limparEntrada();
                nivel = (char) toupper((unsigned char) nivel);
                listarPorNivelOrdenado(&time, nivel);
                break;

            case 2:
                printf("Nome do funcionario: ");
                lerLinha(nomeBusca, sizeof(nomeBusca));
                {
                    int idx = buscarFuncionarioPorNome(&time, nomeBusca);
                    if (idx >= 0) {
                        mostrarFuncionario(&time.funcionarios[idx]);
                    } else {
                        printf("Funcionario nao encontrado.\n");
                    }
                }
                break;

            case 3:
                printf("Informe o nivel (J/P/S): ");
                scanf(" %c", &nivel);
                limparEntrada();
                nivel = (char) toupper((unsigned char) nivel);
                mostrarQuedasDePerformance(&time, nivel);
                break;

            case 0:
                printf("Encerrando o sistema.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
