#include <iostream>
#include <vector>
#include <queue>
#define LIMITE 100000001

using namespace std;

vector<int> dist;
vector<bool> visitados;
vector<vector<pair<int, int>>> grafo, auxiliar;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;

void inicializa(int n){
    grafo.assign(n + 1, vector<pair<int, int> >());
    visitados.assign(n + 1, false);
    dist.assign(n + 1, LIMITE);
    dist[1] = 0;
}

void adicionaGrafo(int u, int v, int w){
    grafo[u].push_back(make_pair(v, w));
    grafo[v].push_back(make_pair(u, w));
}

void montaGrafoAuxiliar(int n){
    auxiliar.assign(n + 1, vector<pair<int, int> >());
    
    for(int u = 1; u <= n; ++u){
        for(int i = 0; i < grafo[u].size(); ++i){
            pair<int, int> v = grafo[u][i];

            for(int j = 0; j < grafo[v.first].size(); ++j){
                pair<int, int> w = grafo[v.first][j];

                auxiliar[u].push_back(make_pair(w.first, v.second + w.second));
                auxiliar[w.first].push_back(make_pair(u, v.second + w.second));
            }
        }
    }
}

int Dijsktra(int src, int dest){
    fila.push(make_pair(0, src));

    while(!fila.empty()){
        pair<int, int> proximo = fila.top();
        fila.pop();

        int d = proximo.first;
        int u = proximo.second;

        if(d > dist[u])   continue;

        if(!visitados[u]){
            visitados[u] = true;
            
            for(int i = 0; i < auxiliar[u].size(); ++i){
                pair<int, int> v = auxiliar[u][i];

                if(dist[u] + v.second < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    fila.push(make_pair(dist[v.first], v.first));
                }
            }
        }
    }

    return dist[dest];
}

int main(){
    int C, V, u, v, w, resultado;

    cin >> C >> V;
    inicializa(C);
    for(int i = 0; i < V; ++i){
        cin >> u >> v >> w;
        adicionaGrafo(u, v, w);
    }
    montaGrafoAuxiliar(C);
    resultado = Dijsktra(1, C);
    if(resultado == LIMITE){
        cout << -1 << endl;
    }else{
        cout << resultado << endl;
    }

    return 0;
}