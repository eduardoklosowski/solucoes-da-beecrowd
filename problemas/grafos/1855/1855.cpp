#include <iostream>
#include <vector>
using namespace std;

int x, y;
vector<string> matriz;
vector<vector<bool>> visitado;

pair<int, int> proximo(char dir) {
  switch (dir) {
  case '>':
    return pair<int, int>(0, 1);
  case '<':
    return pair<int, int>(0, -1);
  case 'v':
    return pair<int, int>(1, 0);
  case '^':
    return pair<int, int>(-1, 0);
  default:
    return pair<int, int>(0, 0);
  }
}

bool buscaTesouro(int i, int j, char dir) {
  if (i < 0 || i >= y || j < 0 || j >= x) {
    return false;
  }
  visitado[i][j] = true;
  if (matriz[i][j] == '*') {
    return true;
  }
  if (matriz[i][j] == '.') {
    pair<int, int> prox = proximo(dir);
    if (!visitado[i + prox.first][j + prox.second]) {
      return buscaTesouro(i + prox.first, j + prox.second, dir);
    }
  }
  pair<int, int> prox = proximo(matriz[i][j]);
  if (!visitado[i + prox.first][j + prox.second]) {
    return buscaTesouro(i + prox.first, j + prox.second, matriz[i][j]);
  }
  return false;
}

int main() {
  string linha;

  cin >> x >> y;

  visitado.assign(x, vector<bool>());
  for (int i = 0; i < y; ++i) {
    cin >> linha;
    matriz.push_back(linha);
    visitado[i].assign(y, false);
  }

  if (matriz[0][0] != '.' && buscaTesouro(0, 0, matriz[0][0])) {
    cout << "*" << endl;
  } else {
    cout << "!" << endl;
  }

  return 0;
}