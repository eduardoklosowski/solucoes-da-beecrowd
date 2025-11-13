# 1148 - Países em Guerra

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1148)

## Solução

Já que o número de cidades é pequeno e temos várias consultas para o mesmo mapa, podemos usar o algoritmo de [Floyd-Warshall](../../../base-teorica/grafos/caminhos/README.md#algoritmo-de-floyd-warshall) para determinar todos eles e podermos fazer as consultas em $O(1)$. Única coisa a se lembrar é que para todo par de vértices $u$ e $v$ que possuem ambas arestas entre si possuem caminhos de custo sempre zero, então é importante ajustar isso antes de começar o _Floyd-Warshall_.