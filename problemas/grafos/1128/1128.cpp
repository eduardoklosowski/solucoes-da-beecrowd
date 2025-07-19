#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grafo;
vector<bool> visitados;

void DFS(int u){
    visitados[u] = true;

    for(int i = 0; i < grafo[u].size(); ++i){
        if(!visitados[grafo[u][i]]){
            DFS(grafo[u][i]);
        }
    }
}

int main(){
    bool resposta;
    int N, M, V, W, P;

    while(cin >> N >> M){
        if(!N && !M)    break;

        grafo.assign(N + 1, vector<int>());
        for(int i = 0; i < M; ++i){
            cin >> V >> W >> P;

            grafo[V].push_back(W);
            if(P == 2){
                grafo[W].push_back(V);
            }
        }

        resposta = true;
        for(int i = 1; i <= N; ++i){
            visitados.assign(N + 1, false);
            DFS(i);
            for(int j = 1; j <= N; ++j){
                resposta = resposta && visitados[j];
                if(!resposta)   break;
            }
            if(!resposta)   break;
        }

        cout << resposta << endl;
    }

    return 0;
}