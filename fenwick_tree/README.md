# Fenwick Tree (Indexed Binary Tree)

Uma estrutura de dados utilizada para manter o tracking das somas de prefixos de um array que muda os valores dos elementos contidos.  
Cada elemento não é responsável por guardar a soma de todos os elementos anteriores, ao invés disso, cada elemento tem alguns elementos em sua responsabilidade, e quantos elementos estão sob a responsabilidade de cada um dos componentes dessa árvore é denominada pelo valor do último `1` na representação binária do índice de um determinado elemento, ou seja:

| índice do elemento | valor em binário | numero de elementos responsável |
|--------------------|------------------|---------------------------------|
| 10 | 1010 | 2 |
| 9 | 1001 | 1 |
| 8 | 1000 | 8 |
| 7 | 0111 | 1 |
| 6 | 0110 | 2 |
| 5 | 0101 | 1 |
| 4 | 0100 | 4 |
| 3 | 0011 | 1 |
| 2 | 0010 | 2 |
| 1 | 0001 | 1 |

Podemos notar com isso que:

1. Todo elemento em índice ímpar (lembrando que os índices dessa estrutura começam em 1) é responsável apenas pelo seu próprio valor;
2. Todo elemento em um índice que é uma potência de 2 é responsável por n elementos anteriores tal que n é igual ao valor de seu índice;
3. Todo elemento em um índice par que não é uma potência de 2 é responsável por 2 elementos, ele próprio e o anterior.

Dessa forma conseguimos atualizar os valores das somas de prefixo de uma maneira otimizada.