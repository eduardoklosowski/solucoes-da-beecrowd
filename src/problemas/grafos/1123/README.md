# 1123 - Desvio de Rota

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1123)

## Solução

Aqui podemos aplicar o [algoritmo de Dijkstra](../../../base-teorica/grafos/caminho-minimo/README.md#algoritmo-de-dijkstra), mas temos que fazer uma leve adaptação no grafo de entrada. Se ao entrar em qualquer uma das cidades do percurso nos obriga a seguir o percurso inteiro à risca, então para podermos usar o algoritmo corretamente nós temos que ir em cada vértice $v_{i}$ do percurso $v_{1}, \ldots, v_{n}$, remover todas as arestas e adicionar apenas uma aresta que vai direto ao final do percurso $v_{n}$ com peso $\sum\limits_{j = i}^{n}{v_{j}}$. Dessa forma, podemos garantir que se o caminho envolve um dos vértices do percurso fixo, então todo o resto do percurso vai ser respeitado.