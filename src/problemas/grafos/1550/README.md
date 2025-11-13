# 1550 - Inversão

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1550)

## Solução

Para todo problema no molde "qual é o menor número de passos para chegar de A até B" onde todos os passos têm o mesmo peso, podemos logo pensar em [busca em largura](../../../base-teorica/grafos/percursos/README.md#busca-em-largura). Nesse caso, a busca em largura guarda dois valores: o número e a quantidade de passos necessária para chegar naquele número. No momento em que o número é igual a B, a resposta é então o número de passos necessários para chegar lá. Note que no código eu coloquei um conjunto que controla se um dado número já foi visto ou não. Isso é importante para que evitemos computar de novo um número que já calculamos a resposta previamente.