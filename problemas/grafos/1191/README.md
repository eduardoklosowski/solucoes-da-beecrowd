# 1191 - Recuperação da Árvore

## [Descrição](https://www.beecrowd.com.br/judge/pt/problems/view/1191)

## Solução

Os percursos prefixo, infixo e posfixo são explicados com mais detalhes no artigo de [árvore binária de busca](../../../base-teorica/grafos/arvore-binaria-de-busca/README.md#percursos).

Repare que a estrutura do prefixo é tal que primeiro vez a raiz, depois a árvore esquerda e depois a direita. Com isso, sabemos logo de cara que a primeira letra do percurso prefixo é a raiz da árvore. Agora, como o percurso infixo traz a árvore esquerda, depois a raiz e depois a árvore direita, se pesquisarmos onde a letra está no percurso infixo e dividirmos a _string_ do percurso infixo em duas, antes e depois da letra, então teremos todas as letras da árvore do lado esquerdo e todas as letras da árvore do lado direito separadas em duas _strings_.

A ideia então do exercício é fazer isso de forma recursiva, usando a ordem da _string_ prefixa para definir a nova raiz. Como a raiz esquerda vem antes na ordem prefixa, então chamamos recursivamente primeiro para a _string_ esquerda e depois para a _string_ direita.

Uma vez que a árvore esteja montada, podemos então percorrê-la na ordem posfixa para imprimirmos a resposta.