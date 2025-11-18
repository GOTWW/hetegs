#include <stdio.h>
#include <string.h>
#include "performance.h"

void inicializarTime(TimeTI *t) {
    t->quantidade = 0;
}

void adicionarFuncionario(TimeTI *t, Funcionario f) {
    if (t->quantidade < MAX_FUNC) {
        t->funcionarios[t->quantidade] = f;
        t->quantidade++;
    } else {
        printf("Nao e possivel adicionar mais funcionarios (limite atingido).\n");
    }
}

void calcularMetricasFuncionario(Funcionario *f) {
    float soma = 0.0f;
    int i;
    for (i = 0; i < NUM_PERIODOS; i++) {
        soma += f->performance[i];
    }
    f->media = soma / NUM_PERIODOS;
    if (NUM_PERIODOS >= 2) {
        f->variacao = f->performance[NUM_PERIODOS - 1] -
                       f->performance[NUM_PERIODOS - 2];
    } else {
        f->variacao = 0.0f;
    }
}

void calcularMetricasTime(TimeTI *t) {
    int i;
    for (i = 0; i < t->quantidade; i++) {
        calcularMetricasFuncionario(&t->funcionarios[i]);
    }
}

static void copiarPorNivel(const TimeTI *t, char nivel,
                           Funcionario destino[], int *qtdDestino) {
    int i;
    *qtdDestino = 0;
    for (i = 0; i < t->quantidade; i++) {
        if (t->funcionarios[i].nivel == nivel) {
            destino[*qtdDestino] = t->funcionarios[i];
            (*qtdDestino)++;
        }
    }
}

static void ordenarPorMediaDesc(Funcionario v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j].media < v[j + 1].media) {
                Funcionario temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void listarPorNivelOrdenado(const TimeTI *t, char nivel) {
    Funcionario listaNivel[MAX_FUNC];
    int qtdNivel, i;

    copiarPorNivel(t, nivel, listaNivel, &qtdNivel);

    if (qtdNivel == 0) {
        printf("\nNao ha funcionarios do nivel %c.\n", nivel);
        return;
    }

    ordenarPorMediaDesc(listaNivel, qtdNivel);

    printf("\nFuncionarios do nivel %c ordenados por media de performance:\n",
           nivel);
    for (i = 0; i < qtdNivel; i++) {
        mostrarFuncionario(&listaNivel[i]);
    }
}

int buscarFuncionarioPorNome(const TimeTI *t, const char *nome) {
    int i;
    for (i = 0; i < t->quantidade; i++) {
        if (strcmp(t->funcionarios[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrarFuncionario(const Funcionario *f) {
    int i;
    printf("\nNome: %s\n", f->nome);
    printf("Nivel: %c\n", f->nivel);
    printf("Performance: ");
    for (i = 0; i < NUM_PERIODOS; i++) {
        printf("%.2f ", f->performance[i]);
    }
    printf("\nMedia: %.2f\n", f->media);
    printf("Variacao (ultimo - penultimo): %.2f\n", f->variacao);
    if (f->variacao < 0) {
        printf("Observacao: queda de performance recente.\n");
    } else if (f->variacao > 0) {
        printf("Observacao: aumento de performance recente.\n");
    } else {
        printf("Observacao: performance estavel nos dois ultimos periodos.\n");
    }
    printf("\n");
}

void mostrarQuedasDePerformance(const TimeTI *t, char nivel) {
    int i;
    int encontrou = 0;
    printf("\nFuncionarios do nivel %c com queda de performance recente:\n",
           nivel);
    for (i = 0; i < t->quantidade; i++) {
        const Funcionario *f = &t->funcionarios[i];
        if (f->nivel == nivel && f->variacao < 0) {
            mostrarFuncionario(f);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum funcionario com queda de performance recente nesse nivel.\n");
    }
}
