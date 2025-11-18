#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#define MAX_FUNC 100
#define NUM_PERIODOS 6

typedef struct {
    char nome[50];
    char nivel; // 'J', 'P' ou 'S'
    float performance[NUM_PERIODOS];
    float media;
    float variacao; // ultimo - penultimo periodo
} Funcionario;

typedef struct {
    Funcionario funcionarios[MAX_FUNC];
    int quantidade;
} TimeTI;

void inicializarTime(TimeTI *t);
void adicionarFuncionario(TimeTI *t, Funcionario f);
void calcularMetricasFuncionario(Funcionario *f);
void calcularMetricasTime(TimeTI *t);
void listarPorNivelOrdenado(const TimeTI *t, char nivel);
int buscarFuncionarioPorNome(const TimeTI *t, const char *nome);
void mostrarFuncionario(const Funcionario *f);
void mostrarQuedasDePerformance(const TimeTI *t, char nivel);

#endif
