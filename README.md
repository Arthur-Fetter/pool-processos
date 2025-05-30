# POOL DE PROCESSOS

Este processo implementa um pool de processos em C++.

O gerenciador de processos possui as seguintes interfaces para interação com o usuário:
- Criação de um processo: O usuário pode criar um processo, como os indicados abaixo. O processo criado é adicionado a uma fila.
- Executar próximo: O gerenciador executa o próximo processo da fila.
- Executar específico: O gerenciador executa um processo baseado no *process id* indicado pelo usuário.

Outras funções que não dependem da interação com o usuário, mas são importantes:
- Salvar a fila de processos: Toda vez que um processo é executado ou adicionado, a fila deve ser salva.
- Carregar a fila de processos: Toda vez que a o gerenciador é iniciado, deve ser carregada a fila existente de processos.

São quatro os tipos de processos que podem ser executados no contexto do nosso pool de processos:
- Processo de cálculo: Executa imprime o resultado do cálculo de uma operação com dois operandos e um operador.
- Processo de gravação: Grava uma expressão aritimética em um arquivo computation.txt.
- Processo de leitura: Lê o arquivo computation.txt e cria um processo de cálculo para cada um dos registros, limpando o arquivo ao fim da leitura.
- Processo de impressão: Imprime na tela o *process id*, tipo do processo e seus atributos.
