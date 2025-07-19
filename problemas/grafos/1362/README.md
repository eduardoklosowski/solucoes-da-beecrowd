# 1362 - Minha Camiseta Me Serve

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1362)

## Solução

Aplicação direta do [algoritmo de fluxo máximo](../../../base-teorica/grafos/fluxo-maximo/README.md).

A modelagem do nosso grafo fica da seguinte forma:

* Vértice $0$ para a fonte
* Vértices de $1$ até $M$ inclusive para os voluntários
* Vértices de $M + 1$ até $M + 6$ inclusive para os tamanhos das camisas
* Vértice $M + 7$ para o sumidouro
* Arestas $0 \rightarrow 1, \ldots, 0 \rightarrow M$ para representar cada pessoa com peso $1$
* Arestas entre cada pessoa e os tamanhos que cada pessoa veste com peso $1$
* Arestas $M + 1 \rightarrow M + 7, \ldots, M + 1 \rightarrow M + 7$ para representar quantas camisas de cada tem, com peso $\frac{N}{6}$

Com essa modelagem, podemos definir bem quais as camisas que cada pessoa pode escolher e também evitamos casos como uma pessoa pegar mais de uma camisa. Se o fluxo for exatamente igual ao número de pessoas, isso é, todo o mundo poder sair a partir da fonte e chegar no sumidouro, isso significa que todo o mundo conseguiu exatamente uma camisa.