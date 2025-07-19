# 1931 - Mania de Par

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1931)

## Solução

Aqui podemos implementar o [algoritmo de Dijkstra](../../../base-teorica/grafos/caminho-minimo/README.md#algoritmo-de-dijkstra) para encontrar o menor caminho da cidade $1$ até a cidade $C$, mas como Patrícia tem a estranha mania de só seguir caminhos pares, temos que alterar o grafo de modo que, não importa qual caminho seja o mínimo, a quantidade de pedágios que ela pague seja sempre par, ou seja, que a quantidade de arestas que ela escolha seja sempre par.

Para isso, podemos montar um outro grafo e, para cada par de arestas $uv$ e $vw$, onde $u, v, w \in V$ e $uv, vw \in E$ no grafo original $G = (V, E)$, criamos uma nova aresta $uw$ no grafo novo onde $peso(uw) = peso(uv) + peso(vw)$. Esse processo é como se a gente estivesse pegando todos os pares de arestas conectados por um vértice e pulando esse vértice fazendo uma aresta que passa pelos dois, forçando que toda vez que escolhemos uma aresta no grafo novo estamos escolhendo duas arestas no grafo original, fazendo com que todo caminho possível no grafo novo seja um caminho par no grafo antigo.

Com isso, ao executar o algoritmo de Dijkstra no grafo novo, sabemos que o algoritmo vai retornar o caminho mínimo onde o número de pedágios pagos é sempre par.