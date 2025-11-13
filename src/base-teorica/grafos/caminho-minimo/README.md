# Caminho mínimo

## Motivação

Um caminho entre dois vértices $u$ e $v$ de um grafo $G = (V, E)$ onde $u, v \in V$ é uma sequência de arestas em $E$ onde o vértice inicial é $u$ e o vértice final é $v$. O problema de caminhos no grafo pode ser expresso de várias formas diferentes:

1. Existe um caminho entre dois vértices $u$ e $v$ de um grafo?
2. Existe um caminho para todos os vértices de um grafo?
3. Qual o menor caminho entre dois vértices $u$ e $v$ de um grafo?
4. Qual o menor caminho entre quaisquer dois vértices de um grafo?

As questões 1 e 2 são mais fáceis de responder, podendo ser respondidas apenas percorrendo o grafo (ver a página de [percursos](../percursos/README.md) para entender mais). Já as questões 3 e 4 envolvem diversos aspectos, incluindo o próprio grafo em si. Por exemplo, se o grafo não tem peso entre as arestas, então esse problema pode ser resolvido com [busca em largura](../percursos/README.md#busca-em-largura), mas caso tenha peso, pode ser que a busca em largura dê resultados não-ótimos. Imagine um caso em que existem dois caminhos possíveis: um de duas arestas de valor pequeno e outro com uma aresta só, mas de valor muito grande. Nesse caso, seria preferível pegar o caminho com mais arestas mas com valor menor. Os algoritmos descritos abaixo servem para sermos capazes de discernir essas opções.

## Algoritmo de Dijkstra

Esse algoritmo é baseado na [busca em largura](../percursos/README.md#busca-em-largura), mas em vez de usar uma [fila](../../estruturas-e-bibliotecas/fila/README.md) para preservar a ordem em que as soluções são cogitadas, usamos uma [fila de prioridade](../../estruturas-e-bibliotecas/fila-de-prioridade/README.md). A ideia da fila de prioridade é, em vez de ordenar pela ordem que os possíveis caminhos aparecem, ordenar em vez disso pelo tamanho do caminho. Dessa forma, caminhos menores teriam mais prioridade na busca, enquanto caminhos maiores podem ser descartados caso não sejam mais necessários.

Enquanto na busca em largura podemos parar na primeira vez que chegamos no resultado correto, no algoritmo de Dijkstra temos que conduzir a busca até o final, pois ao contrário da busca em largura não há uma garantia teórica de um resultado ótimo antes do algoritmo chegar ao fim.

### Implementações

#### C++
```cpp
int Dijsktra(const vector<vector<pair<int, int>>> &grafo, int src, int dest){
    int n = grafo.size();
    // INF seria um valor razoavelmente grande
    vector<int> dist(n, INF);

    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        pair<int, int> aresta = pq.top();
        pq.pop();

        int d = aresta.first;
        int u = aresta.second;

        if(d > dist[u]) continue;
        for(int i = 0; i < grafo[u].size(); ++i){
            pair<int, int> v = grafo[u][i];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }

    return dist[dest];
}
```

## Algoritmo de Bellman-Ford

Repare que no algoritmo de Dijkstra nós adicionamos o peso da nova aresta do caminho e adicionamos o caminho novo com o peso novo na fila de prioridade, o que aumenta a prioridade daquele caminho na fila e eventualmente o torna inválido. Isso só dá certo entretanto para o caso em que todos os pesos são positivos. Se algum peso no grafo for negativo, o valor do caminho sempre diminui e isso faz com que o caminho sempre seja válido e o algoritmo execute para sempre. Nesses casos, precisamos então usar o algoritmo de Bellman-Ford, que é capaz de lidar com pesos negativos.

### Implementações

_Em breve._

## Algoritmo de Floyd-Warshall

O algoritmo de Floyd-Warshall se propõe a, em uma matriz $|V| \times |V|$, apresentar todos os caminhos mínimos para quaisquer pares do grafo $G = (V, E)$. Para isso, ele inicializa a matriz da seguinte forma:

$$
M_{uv} = 
\begin{cases}
peso(uv) \text{, se } uv \in E, \\
0 \text{, se } u = v, \\
\infty \text{, caso contrário}
\end{cases}
$$

$\infty$ no caso sendo representado em código com um valor muito grande. A partir dessa inicialização então, o algoritmo testa todos os caminhos intermediários e, com eles, forma o menor caminho entre todos os pares de vértices possíveis.

### Implementações

#### C++
```cpp
void FloydWarshall(const vector<vector<long long int>> &grafo) {
  int N = grafo.size();
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]);
      }
    }
  }
}
```

## Problemas

* [1123 - Desvio de Rota](../../../problemas/grafos/1123/README.md)
* [1148 - Países em Guerra](../../../problemas/grafos/1148/README.md)
* [1931 - Mania de Par](../../../problemas/grafos/1931/README.md)