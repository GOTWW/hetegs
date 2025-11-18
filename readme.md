Analista de Performance de Times de TI com Apoio de IA  

Em equipes de TI, especialmente em ambientes ágeis, é comum medir produtividade e performance por meio de indicadores como tarefas concluídas, bugs corrigidos, incidentes resolvidos e prazos cumpridos. Com o crescimento da inteligência artificial, tornou-se possível analisar grandes volumes de dados de performance e gerar insights personalizados para cada profissional, de acordo com seu nível (junior, pleno, sênior).

Neste cenário, uma IA corporativa analisa continuamente os dados de desempenho do time de TI e gera informações estruturadas para cada colaborador, identificando momentos de queda de rendimento, picos de produtividade e padrões relevantes ao longo do tempo.
 
O papel do Analista de Performance é receber os dados gerados pela IA, interpretá-los e apoiar ações para aumentar e otimizar a performance de cada pessoa, sempre comparando profissionais do mesmo nível (junior com junior, pleno com pleno, sênior com sênior).

Para apoiar esse analista, desenvolvemos um programa em C que:

- Registra profissionais de TI e seus níveis (junior, pleno, sênior);
- Armazena indicadores de performance ao longo de vários períodos (por exemplo, sprints ou meses);
- Compara profissionais do mesmo nível;
- Identifica quando a performance de um profissional caiu ou aumentou recentemente;
- Ordena profissionais de um mesmo nível por desempenho médio;
- Ajuda o analista a identificar quem precisa de atenção, quem está acima da média e onde ocorreram quedas de performance.

assim podemos criar um sistema em C que simule o trabalho do Analista de Performance usando dados vindos de uma IA (no programa, os dados são digitados pelo usuário), utilizando estruturas de dados e algoritmos adequados (TAD, ordenação e busca).

Prompt IA:

Você é um desenvolvedor especialista em linguagem C e em estruturas de dados.

Preciso que você implemente um programa em C que simule o trabalho de um Analista de Performance de um time de TI.

Requisitos do programa:
1. Deve existir um Tipo Abstrato de Dados (TAD) para representar um funcionário de TI, contendo:
   - nome (string),
   - nível (caractere: 'J' para junior, 'P' para pleno, 'S' para sênior),
   - um vetor de valores de performance ao longo de vários períodos (por exemplo, 6 períodos),
   - campos para armazenar a média de performance e uma métrica de variação (por exemplo, diferença entre o último e o penúltimo período).

2. Deve existir uma estrutura para armazenar um conjunto de funcionários (por exemplo, um vetor de funcionários e um campo com a quantidade).

3. O programa deve:
   - Ler do teclado os dados de vários funcionários (nome, nível e valores de performance em cada período).
   - Calcular a média e a variação de performance de cada funcionário.
   - Permitir listar funcionários de um determinado nível (junior, pleno ou sênior) ordenados pela média de performance (use um algoritmo de ordenação explícito, como Bubble Sort, Selection Sort ou Insertion Sort).
   - Permitir buscar um funcionário pelo nome e mostrar seu histórico de performance, média e variação.

4. O programa deve ser estruturado em funções.

5. O código deve compilar com gcc sem erros.

Gere o código completo em C, incluindo #include, typedef, funções, main e comentários explicando cada parte importante.
