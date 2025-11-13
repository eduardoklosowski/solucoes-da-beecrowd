#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arestas;
vector<vector<pair<int, int>>> grafo;
vector<bool> visitados;

void inicializaGrafo(int n){
    grafo.assign(n, vector<pair<int, int> >());
}

void adicionaAresta(int u, int v, int w){
    u -= 1;
    v -= 1;
    grafo[u].push_back(make_pair(v, w));
    grafo[v].push_back(make_pair(u, w));
}

void adicionaVizinhosFila(int u){
    for(int i = 0; i < grafo[u].size(); ++i){
        if(!visitados[grafo[u][i].first]){
            arestas.push(make_pair(grafo[u][i].second, grafo[u][i].first));
        }
    }
}

int Prim(){
    int custo = 0;
    int visitas = 0;
    int n = grafo.size();

    visitados.assign(n, false);

    visitas += 1;
    visitados[0] = true;
    adicionaVizinhosFila(0);

    while(visitas < n){
        pair<int, int> aresta = arestas.top();
        arestas.pop();

        if(!visitados[aresta.second]){
            visitas += 1;
            custo += aresta.first;
            visitados[aresta.second] = true;

            adicionaVizinhosFila(aresta.second);
        }
    }

    return custo;
}

int main(){
    int R, C, V, W, P;

    cin >> R >> C;
    inicializaGrafo(R);
    for(int i = 0; i < C; ++i){
        cin >> V >> W >> P;
        adicionaAresta(V, W, P);
    }
    cout << Prim() << endl;

    return 0;
}