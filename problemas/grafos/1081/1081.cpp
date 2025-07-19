#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> visitado;
int V, E;
int M[32][32];

bool DFS(int v, int lvl) {
  visitado[v] = true;

  bool imprimiu = false;
  for (int i = 0; i < V; ++i) {
    if (M[v][i]) {
      imprimiu = true;
      for (int j = 0; j < lvl; ++j)
        cout << "  ";
      cout << v << "-" << i;

      if (!visitado[i]) {
        cout << " pathR(G," << i << ")" << endl;
        DFS(i, lvl + 1);
      } else {
        cout << endl;
      }
    }
  }

  return imprimiu;
}

int main() {
  int T, x, y, k;

  cin >> T;
  k = 0;

  while (T--) {
    cin >> V >> E;

    visitado.assign(V, false);
    memset(M, 0, sizeof(M));

    for (int i = 0; i < E; ++i) {
      cin >> x >> y;

      M[x][y] = 1;
    }

    cout << "Caso " << ++k << ":" << endl;

    for (int i = 0; i < V; ++i) {
      if (!visitado[i]) {
        if (DFS(i, 1)) {
          cout << endl;
        }
      }
    }
  }

  return 0;
}