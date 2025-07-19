#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define INFINITO 1000000

using namespace std;

vector<map<int, int>> adaptaGrafo(vector<map<int, int>> &grafo) {
  vector<map<int, int>> resposta =
      vector<map<int, int>>(grafo.size(), map<int, int>());

  int n = grafo.size();
  for (int i = 0; i < n; ++i) {
    int m = grafo[i].size();
    for (map<int, int>::iterator it = grafo[i].begin(); it != grafo[i].end();
         ++it) {
      resposta[i][it->first] = it->second;
      resposta[it->first][i] = it->second;
    }
  }

  return resposta;
}

pair<vector<int>, int> encontraCaminho(vector<map<int, int>> &grafo, int fonte,
                                       int sumidouro) {
  queue<int> fila;
  vector<int> pai(grafo.size(), -1);
  vector<bool> visitado(grafo.size(), false);

  visitado[fonte] = true;
  fila.push(fonte);

  while (!fila.empty()) {
    int u = fila.front();
    fila.pop();

    if (u == sumidouro) {
      break;
    }

    for (map<int, int>::iterator it = grafo[u].begin(); it != grafo[u].end();
         ++it) {
      int v = it->first;
      int peso = it->second;

      if (peso > 0 && !visitado[v]) {
        visitado[v] = true;
        fila.push(v);
        pai[v] = u;
      }
    }
  }

  if (!visitado[sumidouro]) {
    return pair<vector<int>, int>(vector<int>(), 0);
  }

  vector<int> resposta;
  int fluxo = INFINITO;

  int v = sumidouro;
  while (v != fonte) {
    resposta.push_back(v);
    fluxo = min(fluxo, grafo[pai[v]][v]);

    v = pai[v];
  }
  resposta.push_back(fonte);

  return pair<vector<int>, int>(resposta, fluxo);
}

int fluxoMaximo(vector<map<int, int>> &grafo, int fonte, int sumidouro) {
  vector<map<int, int>> novo_grafo = adaptaGrafo(grafo);

  int resposta = 0;

  while (true) {
    pair<vector<int>, int> caminho =
        encontraCaminho(novo_grafo, fonte, sumidouro);

    int fluxo = caminho.second;
    if (fluxo == 0) {
      break;
    }
    resposta += fluxo;

    for (int i = caminho.first.size() - 1; i > 0; --i) {
      int u = caminho.first[i];
      int v = caminho.first[i - 1];

      novo_grafo[u][v] -= fluxo;
      novo_grafo[v][u] += fluxo;
    }
  }

  return resposta;
}

int converte(int m, string tamanho) {
  if (tamanho == "XXL")
    return m + 1;
  if (tamanho == "XL")
    return m + 2;
  if (tamanho == "L")
    return m + 3;
  if (tamanho == "M")
    return m + 4;
  if (tamanho == "S")
    return m + 5;
  if (tamanho == "XS")
    return m + 6;
  return m;
}

int main() {
  int T, N, M;
  string tamanho1, tamanho2;

  cin >> T;
  for (int k = 0; k < T; ++k) {
    cin >> N >> M;
    N /= 6;

    vector<map<int, int>> grafo = vector<map<int, int>>(M + 8, map<int, int>());
    for (int u = 1; u <= M; ++u) {
      grafo[0][u] = 1;

      cin >> tamanho1 >> tamanho2;
      int v = converte(M, tamanho1);
      grafo[u][v] = 1;
      v = converte(M, tamanho2);
      grafo[u][v] = 1;
    }
    for (int i = M + 1; i <= M + 6; ++i) {
      grafo[i][M + 7] = N;
    }

    if (fluxoMaximo(grafo, 0, M + 7) == M) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}