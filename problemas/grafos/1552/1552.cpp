#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<pair<int, double>>> grafo;
vector<pair<double, pair<int, int>>> arestas;

class UnionFind{
    private:
    vector<int> conjunto, rank;

    public:
    UnionFind(int N){
        rank.assign(N, 0);
        conjunto.assign(N, 0);
        for(int i = 0; i < N; ++i){
            conjunto[i] = i;
        }
    }

    int findSet(int i){
        return (conjunto[i] == i) ? i : (conjunto[i] = findSet(conjunto[i]));
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y]){
                conjunto[y] = x;
            }else{
                conjunto[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
    }
};

void inicializaGrafo(int n){
    grafo.assign(n, vector<pair<int, double> >());
}

void adicionaAresta(int u, int v, double w){
    grafo[u].push_back(make_pair(v, w));
    arestas.push_back(make_pair(w, make_pair(u, v)));
}

double distancia(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double Kruskal(int n, int m){
    UnionFind UF(n);
    double custo = 0;

    sort(arestas.begin(), arestas.end());

    for(int i = 0; i < m; ++i){
        pair<double, pair<int, int> > aresta = arestas[i];
        
        if(!UF.isSameSet(aresta.second.first, aresta.second.second)){
            custo += aresta.first;
            UF.unionSet(aresta.second.first, aresta.second.second);
        }
    }

    return custo;
}

int main(){
    int C, n;
    double x, y;
    vector<pair<double, double> > coordenadas;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C;
    for(int i = 0; i < C; ++i){
        cin >> n;

        arestas.clear();
        inicializaGrafo(n);
        coordenadas.assign(n, make_pair(0, 0));

        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            x /= 100.0;
            y /= 100.0;

            coordenadas[i] = make_pair(x, y);
            for(int j = i - 1; j > -1; --j){
                adicionaAresta(i, j, distancia(coordenadas[i], coordenadas[j]));
            }
        }

        cout << setprecision(2) << fixed << Kruskal(n, arestas.size()) << endl;
    }

    return 0;
}