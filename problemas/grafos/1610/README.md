# 1610 - Dudu Faz Serviço

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1610)

## Solução

Aqui podemos fazer uma [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade) que guarda duas informações diferentes: quando um vértice entrou na busca em profundidade e quando ele saiu. O tempo pode começar como $0$ e ir somando um a medida que algum valor de entrada ou saída é atualizado. Para o terceiro grafo de teste, por exemplo, a tabela ficaria assim:

|         | 1 | 2 | 3 | 4 |
|---------|---|---|---|---|
| entrada | 0 | 3 | 1 | 2 |
| saída   | 7 | 4 | 6 | 5 |

Para que um grafo $G = (V, E)$ tenha ciclo, é preciso que exista alguma aresta $uv \in E$ onde a saída de $u$ acontece antes da saída de $v$. A primeira vista, nós imaginamos que isso nunca seria possível, já que sendo $v$ é um vizinho de $u$, então primeiro precisaria processar todos os vizinhos de $v$ antes de $u$ terminar.

Vamos então imaginar que existam vértices $v_{1}, \ldots, v_{n} \in V$ tais que $v_{1}v_{2}, \ldots, v_{n - 1}v_{n} \in E$, ou seja, esses vértices fazem parte de um ciclo no grafo. Nesse caso, a busca em largura vai ser chamado primeiramente para um deles (por exemplo, para o $v_{x}$) no ciclo e seguir a ordem até alcançar todos os vértices do ciclo. Ao chegar no último valor visitado $v_{x - 1}$, ele tentará visitar $v_{x}$ do ciclo novamente e não vai conseguir. Aqui é onde encotraremos a discrepância, pois então $v_{x - 1}$ vai terminar a busca e após isso vão terminando $v_{x - 2}, \ldots, v_{x + 1}$ até que $v_{x}$ então possa terminar a busca. Nesse caso, o valor de saída de $v_{x}$ será maior que o valor de saída de $v_{x - 1}$, onde $v_{x - 1}v_{x} \in E$, que é o critério de indicação de ciclo que descrevemos acima.