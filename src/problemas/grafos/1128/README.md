# 1128 - Ir e Vir

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1128)

## Solução

Aqui temos que ver se de qualquer cidade podemos chegar em qualquer outra cidade do mapa. Para isso, para toda cidade, podemos fazer uma [busca em profundidade](../../../base-teorica/grafos/percursos/README.md#busca-em-profundidade) para ver se daquela cidade dá pra chegar nas outras ou não. Se tiver pelo menos uma cidade que não foi marcada como visitada com essa busca, significa que é uma cidade inacessível e que portanto a resposta é 0. Caso dê, de todas as cidades, visitar todas as outras, então a resposta é 1.