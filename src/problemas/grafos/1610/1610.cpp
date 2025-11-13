#include <iostream>
#include <set>
#include <vector>

using namespace std;

int passo;
vector<int> pre, pos;

void DFS(const vector<set<int>> &grafo, int u) {
  pre[u] = passo++;

  for (set<int>::iterator it = grafo[u].begin(); it != grafo[u].end(); ++it) {
    if (pre[*it] == -1) {
      DFS(grafo, *it);
    }
  }

  pos[u] = passo++;
}

bool temCiclo(const vector<set<int>> &grafo) {
  int N = grafo.size();

  passo = 0;
  pre.assign(N, -1);
  pos.assign(N, -1);
  for (int i = 0; i < N; ++i) {
    if (pre[i] == -1) {
      DFS(grafo, i);
    }
  }

  for (int i = 0; i < grafo.size(); ++i) {
    for (set<int>::iterator it = grafo[i].begin(); it != grafo[i].end(); ++it) {
      if (pos[i] < pos[*it]) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int T, N, M, A, B;
  vector<set<int>> grafo;

  cin >> T;
  for (int k = 0; k < T; ++k) {
    cin >> N >> M;

    grafo.assign(N + 1, set<int>());
    for (int i = 0; i < M; ++i) {
      cin >> A >> B;
      grafo[A].insert(B);
    }

    if (temCiclo(grafo)) {
      cout << "SIM" << endl;
    } else {
      cout << "NAO" << endl;
    }
  }

  return 0;
}