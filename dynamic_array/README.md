# Arrays dinâmicos (Dynamic arrays)

Arrays dinâmicos, que são encontrados em linguagens como a lista presente no Python e no Java, os vetores do C++ e do Rust, apresentam uma evolução ao array estáticos. Enquanto arrays estáticos tem um tamanho pré definido e é alocado na memória em *stack* (e é definido durante a compilação), os arrays dinâmicos alocam memória *heap* em tempo de execução o que nos permite adicionar ou tirar elementos efetivamente de um array e adaptamos o tamanho dele de acordo com as operações que o programa fará em tempo de execução.

## Características chaves:

- **Pode mudar de tamanho**: Diferente dos arrays estáticos, os arrays dinâmicos podem mudar de tamanho. O que nos permite adicionar ou retirar elementos do array.
- **Memória contígua**: Da mesma forma que os arrays estáticos, os arrays dinâmicos armazenam seus elementos em um espaço contíguo de memória, ou seja, sempre que mudarmos o tamanho deste array ele deve alocar um espaço diferente da memória para a nova quantidade de elementos ou então extender ou comprimir o espaço preenchido.
- **Indexável**: Assim como os arrays estáticos, os arrays dinâmicos continuam sendo indexável, então acessamos um elemento aleatório em O(1);

## Alocação de memória e Gerenciamento:

O conceito base do array dinâmico pode ser a alocação de memória, através disso conseguimos expandir ou diminuir o tamanho do nosso array para conter mais ou menos elementos. É muito importante ter em mente que como estamos alocando memória em tempo de execução, devemos nos lembrar te desbloquear esse espaço da memória quando a vida útil do nosso array acabar, fazemos isso utilizando a função **free()** do C. Caso alguém execute uma alocação de memória utilizando **malloc()** ou **calloc()** e se esqueça de desbloquear a memória alocada ao terminar a execução do programa temos como resultado o tão famigerado **vazamento de memória**.  
Portanto podemos dizer que cada **malloc()** ou **calloc()** teve ter um respectivo **free()** e podemos verificar se nosso programa vaza memória de alguma forma utilizando o **valgrind**.

## Operações

Para o exemplo de implementação definimos algumas operações, são elas:

- Mudar tamanho;
- Adicionar no final;
- Inserir no índice específico;
- Retirar o último elemento;
- Remover em um índice específico;
- Remover um elemento específico;
- Modificar um elemento específico;
- Acessar um elemento específico;

Todas as outras funções além destas acima servirão apenas para auxiliar na implementação das listadas.