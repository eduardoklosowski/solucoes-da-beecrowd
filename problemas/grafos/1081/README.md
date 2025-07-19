# 1081 - DFSr - Hierarquia de Profundidade

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1081)

## Solução

O enunciado do problema explica como uma [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade) funciona, mas com algumas coisas a mais, como o acréscimo de variáveis para acompanhar se os vértices já foram visitados ou não e uma função chamada `pathR()`. Para resolver o problema, entretanto, você pode fazer uma busca em profundidade normal, apenas prestando atenção em:

* quando se deve pular linha entre componentes, você só pode pular linha se algo tiver sido impresso no componente (isso é, se tem pelo menos dois vértices no componente conexo)
* e guardar a informação da tabulação que você tem que acrescentar antes de imprimir a aresta, o que pode ser feito com um segundo parâmetro na busca em profundidade para indicar o nível em que você está.