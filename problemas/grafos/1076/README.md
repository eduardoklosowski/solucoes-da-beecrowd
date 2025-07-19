# 1076 - Desenhando Labirintos

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1076)

## Solução

A forma ótima de se percorrer um grafo repetindo as arestas o mínimo possível é percorrendo-o através da [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade). Nesse caso, estamos tratando de um grafo com uma única componente conexa sem ciclos, que não podemos chamar de árvore porque nem todos os vértices são conectados, que vamos então considerar que é uma "árvore", assim mesmo, entre aspas.

Com isso em mente, perceba que cada vértice $v$ no grafo só tem um pai $u$ e, logo, $DFS(v)$ só será chamado uma vez para a aresta $uv$ que relaciona $v$ com seu pai. Com isso, para essa aresta em específico, ela será vista duas vezes:

1. Uma vez no começo da chamada de $DFS(v)$, vindo de $uv$;
2. Uma vez ao terminar a chamada de $DFS(v)$, voltando para $DFS(u)$, passando por $uv$.

Logo, sem perda de generalidade, podemos dizer que para toda aresta do grafo, tal aresta é passada exatamente duas vezes. Então a gente nem precisa fazer a busca em profundidade, apenas contar o número de arestas e multiplicar por $2$ já basta. O único cuidado aqui é que precisamos identificar quais arestas são repetidas para não as contarmos duas vezes. Mas usando conjuntos, como colocamos as duas direções por vez, podemos só considerar o tamanho do conjunto como resposta válida.

> Em JavaScript, eu não sabia como que botava tuplas no conjunto, então fiz tipo um _hash_ para relacionar cada aresta com um número inteiro único. Como nunca há mais de 99 vértices nesse grafo, funcionou bem.