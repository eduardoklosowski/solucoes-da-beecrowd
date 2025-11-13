# 1907 - Coloração de Cenários de Jogos

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1907)

## Solução

A solução de [Flood Fill](../../../base-teorica/estruturas-e-bibliotecas/flood-fill/README.md) para esse problema demora muito, mas a solução em [busca em largura](../../../base-teorica/grafos/percursos/README.md#busca-em-largura) funcionou para mim, por algum motivo. Outra coisa interessante de se fazer em problemas desse tipo é colocar uma borda na matriz só com "paredes" (nesse caso, `'o'`) que aí não precisa fazer a verificação se os valores estão dentro ou fora da matriz o tempo todo.