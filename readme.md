Código da IA: codigo_ia.c
GS – Data Structures and Algorithms
Future Skills Lab – Analista de Performance de TI

**O Problema**

Em equipes de TI, especialmente em ambientes ágeis, é comum medir produtividade e performance por meio de indicadores como tarefas concluídas, bugs corrigidos, incidentes resolvidos e prazos cumpridos. Com o crescimento da inteligência artificial, tornou-se possível analisar grandes volumes de dados de performance e gerar insights personalizados para cada profissional, de acordo com seu nível (junior, pleno, sênior).

Neste cenário, uma IA corporativa analisa continuamente os dados de desempenho do time de TI e gera informações estruturadas para cada colaborador, identificando momentos de queda de rendimento, picos de produtividade e padrões relevantes ao longo do tempo.

O papel do Analista de Performance é receber os dados gerados pela IA, interpretá-los e apoiar ações para aumentar e otimizar a performance de cada pessoa, sempre comparando profissionais do mesmo nível (junior com junior, pleno com pleno, sênior com sênior).

Para apoiar esse analista, desenvolvemos um programa em C que:

Registra profissionais de TI e seus níveis (junior, pleno, sênior);

Armazena indicadores de performance ao longo de vários períodos (por exemplo, sprints ou meses);

Compara profissionais do mesmo nível;

Identifica quando a performance de um profissional caiu ou aumentou recentemente;

Ordena profissionais de um mesmo nível por desempenho médio;

Ajuda o analista a identificar quem precisa de atenção, quem está acima da média e onde ocorreram quedas de performance.

Assim, o sistema em C simula o trabalho do Analista de Performance usando dados gerados por uma IA (no programa, os dados são digitados pelo usuário), aplicando estruturas de dados e algoritmos como TAD, ordenação e busca.
**fim**

**O Prompt utilizado na IA**

Texto exato enviado ao AI companion para gerar o primeiro código (codigo_ia.c):

Você é um desenvolvedor especialista em linguagem C e em estruturas de dados.

Preciso que você implemente um programa em C que simule o trabalho de um Analista de Performance de um time de TI.

Requisitos do programa:

Deve existir um Tipo Abstrato de Dados (TAD) para representar um funcionário de TI, contendo:

nome (string),

nível (caractere: 'J' para junior, 'P' para pleno, 'S' para sênior),

um vetor de valores de performance ao longo de vários períodos (por exemplo, 6 períodos),

campos para armazenar a média de performance e uma métrica de variação (por exemplo, diferença entre o último e o penúltimo período).

Deve existir uma estrutura para armazenar um conjunto de funcionários (por exemplo, um vetor de funcionários e um campo com a quantidade).

O programa deve:

Ler do teclado os dados de vários funcionários (nome, nível e valores de performance em cada período).

Calcular a média e a variação de performance de cada funcionário.

Permitir listar funcionários de um determinado nível (junior, pleno ou sênior) ordenados pela média de performance (use um algoritmo de ordenação explícito, como Bubble Sort, Selection Sort ou Insertion Sort).

Permitir buscar um funcionário pelo nome e mostrar seu histórico de performance, média e variação.

O programa deve ser estruturado em funções.

O código deve compilar com gcc sem erros.

Gere o código completo em C, incluindo #include, typedef, funções, main e comentários explicando cada parte importante.
**fim do prompt**

**Análise Crítica do Código da IA**

Correção

O código gerado pela IA compila com gcc sem erros quando salvo corretamente como codigo_ia.c.

A lógica de cálculo da média e da variação está correta:

a média é a soma dos valores de performance dividida por NUM_PERIODOS;

a variação é calculada como “último período menos penúltimo período”.

A leitura dos dados (nome, nível e valores de performance) funciona, mas depende fortemente de scanf e de formatações específicas, o que torna o código sensível a entradas erradas ou a quebras de linha inesperadas.

Toda a lógica (leitura, processamento e exibição) está concentrada em um único arquivo, o que funciona, mas torna a manutenção e a evolução do código mais difíceis.

Eficiência e uso de estruturas de dados

A IA utiliza um vetor simples de Funcionario e uma variável para a quantidade de funcionários. Não há um TAD separado para representar o time como um todo, apenas o struct de Funcionario isolado.

A ordenação é feita usando um algoritmo de complexidade O(n²) (estilo Bubble Sort), o que é aceitável para o limite de MAX_FUNC = 100, mas não está claramente documentado.

A função de ordenação tenta ordenar somente funcionários de um nível específico, porém trabalha em cima do vetor completo. Ela troca posições apenas quando os dois elementos comparados pertencem ao mesmo nível. Isso pode causar um comportamento pouco intuitivo e dificultar a leitura do código.

A busca de funcionários por nome é feita de forma linear (O(n)), o que é suficiente para o contexto da disciplina, mas novamente não é encapsulado em um TAD maior.

Clareza, organização e boas práticas

O código inteiro (tipos, leitura de dados, ordenação, busca e main) está num único arquivo, sem separação em módulos (.h e .c).

Não existe um TAD para o time (por exemplo, um struct com o vetor de funcionários e a quantidade). Essa abstração faria sentido para o problema e deixaria o código mais próximo de boas práticas de estruturas de dados.

A função de ordenação por nível não é muito clara, pois a lógica de “ordenar somente dentro do nível” é feita com condições dentro de um laço que percorre todos os elementos.

A modularização é limitada: poderiam existir funções menores e mais específicas para leitura, cálculo e exibição, além de arquivos separados para o TAD e para a função main.

Faltam mensagens de erro mais detalhadas (por exemplo, tratar melhor níveis inválidos, número excessivo de funcionários, etc.).

Em resumo, o código da IA funciona e cumpre o básico do que foi pedido, mas peca em organização, modularização e clareza da lógica, principalmente na parte de ordenação por nível e na ausência de um TAD para o time.
**fim**

**Solução Refinada (melhorias implementadas no código final)**

A partir da análise crítica do código da IA, foi desenvolvida uma solução refinada, organizada em três arquivos principais: main.c, performance.c e performance.h. As principais melhorias são:

Uso de TAD para representar o time

Foi criado um TAD chamado TimeTI, que encapsula o vetor de funcionários e a quantidade atual:

typedef struct {
Funcionario funcionarios[MAX_FUNC];
int quantidade;
} TimeTI;

Isso deixa explícito que estamos trabalhando com um “time de TI”, facilita a passagem de parâmetros para as funções e melhora a clareza do código.

Separação em módulos (.h e .c)

performance.h define os tipos (Funcionario e TimeTI) e os protótipos das funções do TAD (inicialização, cálculo de métricas, ordenação, busca, exibição, etc.).

performance.c implementa essas funções, concentrando a lógica de negócio (cálculo da média, variação, filtragem por nível, ordenação por desempenho, identificação de quedas de performance).

main.c fica responsável apenas pela interação com o usuário: exibir o menu, ler os dados digitados e chamar as funções do TAD.

Ordenação por nível mais clara

Em vez de tentar ordenar o vetor inteiro misturando todos os níveis, a solução refinada:

copia os funcionários de um determinado nível para um vetor auxiliar;

ordena esse vetor auxiliar pela média de performance em ordem decrescente;

exibe o resultado.

Essa abordagem torna a lógica mais transparente, evitando efeitos colaterais no vetor original e deixando claro para o analista de performance que a comparação é sempre feita “junior com junior”, “pleno com pleno” e “sênior com sênior”.

Funções específicas e reutilizáveis

Foram criadas funções específicas, como:

calcularMetricasFuncionario e calcularMetricasTime,

listarPorNivelOrdenado,

buscarFuncionarioPorNome,

mostrarQuedasDePerformance,

mostrarFuncionario.

Isso melhora a leitura e a manutenção, separando responsabilidades e evitando repetições de código.

Feedback mais rico para o Analista de Performance

A função mostrarFuncionario não apenas imprime os números, mas também traz uma interpretação simples da variação:

se a variação é negativa, destaca que houve queda recente de performance;

se é positiva, destaca aumento;

se é próxima de zero, a performance é considerada estável.

Isso aproxima mais o programa da ideia do Future Skills Lab, em que o profissional do futuro usa ferramentas para interpretar dados gerados por IA, e não apenas olhar números.

Melhor tratamento da entrada de dados

Foram adicionadas funções auxiliares para limpar o buffer e ler linhas de texto, reduzindo problemas com scanf e quebras de linha.

O nível do funcionário é validado (aceita apenas J, P ou S) e é convertido para maiúsculo utilizando toupper, garantindo consistência nas comparações.

Compilação e execução da solução refinada

Para compilar a versão final, são usados os arquivos main.c e performance.c:

gcc main.c performance.c -o analista_performance

Ao executar o programa, o usuário pode:

cadastrar funcionários com seus níveis e histórico de performance;

listar funcionários de um determinado nível ordenados pela média;

buscar um funcionário pelo nome e ver seu histórico;

visualizar quais funcionários tiveram queda recente de performance em um nível específico.
**fim**