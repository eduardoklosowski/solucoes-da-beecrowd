# 1855 - Mapa do Meistre

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1855)

## Solução

Aqui podemos usar uma lógica parecida com a [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade), como no problema [1905 - Polícia e Ladrão](../1905/README.md). Aqui, a diferença é que, ao invés de chamar para todos os vizinhos, nós vamos chamar apenas para o próximo vizinho, de acordo com a direção que estamos seguindo. Confira no código como podemos persistir a direção, em qual momento devemos trocá-la e como sabemos quem é o próximo vizinho.