#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> &visitado, vector<vector<int>> &grafo, int componente,
         int u) {
  visitado[u] = componente;

  for (int i = 0; i < grafo[u].size(); i++) {
    int v = grafo[u][i];

    if (!visitado[v]) {
      DFS(visitado, grafo, componente, v);
    }
  }
}

int main() {
  int N, V, E;
  char u, v;
  vector<int> visitado;
  vector<vector<int>> grafo;

  cin >> N;
  for (int k = 1; k <= N; ++k) {
    cin >> V >> E;

    visitado.assign(V, false);
    grafo.assign(V, vector<int>());

    for (int i = 0; i < E; ++i) {
      cin >> u >> v;

      grafo[u - 'a'].push_back(v - 'a');
      grafo[v - 'a'].push_back(u - 'a');
    }

    cout << "Case #" << k << ":" << endl;
    int componentes = 0;
    for (int u = 0; u < V; ++u) {
      if (visitado[u] == 0) {
        componentes += 1;
        DFS(visitado, grafo, componentes, u);

        vector<char> vertices;
        for (int i = 0; i < V; i++) {
          if (visitado[i] == componentes) {
            vertices.push_back(i + 'a');
          }
        }

        sort(vertices.begin(), vertices.end());

        for (int i = 0; i < vertices.size(); ++i) {
          cout << vertices[i] << ',';
        }
        cout << endl;
      }
    }
    cout << componentes << " connected components" << endl << endl;
  }

  return 0;
}
