#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  return (const int *)a - (const int *)b;
}

void DFS(int *visitado, int **grafo, int n, int p, int u) {
  int v;
  visitado[u] = p;

  for (v = 0; v < n; ++v) {
    if (grafo[u][v] > 0 && visitado[v] == 0) {
      DFS(visitado, grafo, n, p, v);
    }
  }
}

int main(void) {
  int N, V, E, n, componentes;
  int *visitado, *vertices;
  int **grafo;
  char u, v;

  scanf("%d\n", &N);
  for (int k = 1; k <= N; ++k) {
    scanf("%d %d\n", &V, &E);

    grafo = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; ++i) {
      grafo[i] = (int *)malloc(V * sizeof(int));
      for (int j = 0; j < V; ++j) {
        grafo[i][j] = 0;
      }
    }

    for (int i = 0; i < E; ++i) {
      scanf("%c %c\n", &u, &v);
      grafo[u - 'a'][v - 'a'] = 1;
      grafo[v - 'a'][u - 'a'] = 1;
    }

    printf("Case #%d:\n", k);
    visitado = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i) {
      visitado[i] = 0;
    }
    componentes = 0;
    for (int u = 0; u < V; ++u) {
      if (visitado[u] == 0) {
        componentes += 1;
        DFS(visitado, grafo, V, componentes, u);

        n = 0;
        vertices = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; ++j) {
          if (visitado[j] == componentes) {
            vertices[n++] = j;
          }
        }

        qsort(vertices, n, sizeof(int), comp);

        for (int j = 0; j < n; ++j) {
          printf("%c,", vertices[j] + 'a');
        }
        printf("\n");

        free(vertices);
      }
    }
    printf("%d connected components\n\n", componentes);

    free(visitado);
    for (int i = 0; i < V; ++i) {
      free(grafo[i]);
    }
    free(grafo);
  }

  return 0;
}