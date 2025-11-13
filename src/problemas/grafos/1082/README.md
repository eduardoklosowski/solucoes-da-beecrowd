# 1082 - Componentes Conexos

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1082)

## Solução

Aqui eu traduzi as letras para números (usando seus respectivos [códigos ASCII](../../../base-teorica/strings/ascii/README.md)) para ficar mais fácil de transformar em grafo, mas usando dicionários dá pra permanecer como letra, sem problemas.

Para ver quantos componentes conexos tem no grafo, você pode fazer um _loop_ de todos os vértices do grafo e para cada vértice perguntar se ele já foi visitado e caso não tenha sido, contar mais uma componente e executar uma [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade). O vetor visitado que você usa para verificar precisa ser o mesmo entre todas as chamadas de busca em profundidade que você fizer e **não** pode ser reinicializado a cada vértice, já que a ideia é que quando você for pro próximo vértice, se ele fizer parte da mesma componente de algum vértice anterior, que ele já esteja visitado e portanto você não conta mais uma componente, só vai direto pro próximo vértice mesmo.