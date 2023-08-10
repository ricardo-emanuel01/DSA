# Fila

A fila é um tipo de dado abstrato fundamental e muito utilizada na programação e na ciência da computação. Segue o princípio de **primeiro a chegar primeiro a sair** (FIFO), ou seja, se um elemento entra primeiro na fila ele sai primeiro, bem como uma fila de pessoas numa padaria.
A estrutura de dados **fila** assim como uma fila de pessoas é muito útil em cenários em que a ordem dos elementos dessa fila importa. São muito utilizadas em situações como gerenciar tarefas que precisam ser processadas na ordem em que foram recebidas.

## Características chave:

- **É uma estrutura de dados linear**: Assim como os arrays seus elementos seguem uma ordem linear.
- **First-In-First-Out**: Os primeiros elementos a chegar serão os primeiros a sair.
- **Implementação variada**: Pode ser implementada utilizando um array circular estático, array dinâmico ou uma lista ligada.
- Existem variações da **fila**, como exemplo a **fila de prioridade**.

## Operações

A implementação da fila do repositório foi feita com um array circular estático, e definimos as seguintes operações:

- Enfileirar;
- Desenfileirar;

As outras operações serão apenas auxiliares para as operações listadas acima.