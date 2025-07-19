# 1905 - Polícia e Ladrão

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1905)

## Solução

Se imaginarmos que cada posição da matriz é um vértice e as arestas são as direções que podemos ir para cada posição, então podemos fazer uma [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade) nesse grafo para ver se é possível sair da posição do canto superior direito e chegar à posição do canto inferior esquerdo da matriz. Perceba que a ideia não é modelar um grafo, só seguir a ideia do algoritmo para percorrer a matriz.