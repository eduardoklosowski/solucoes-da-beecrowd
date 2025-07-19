#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> grafo;

int Dijsktra(int n, int src, int dest){
    vector<int> dist(n, 62500);

    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        pair<int, int> aresta = pq.top();
        pq.pop();

        int d = aresta.first;
        int u = aresta.second;

        if(d > dist[u]) continue;
        for(int i = 0; i < grafo[u].size(); ++i){
            pair<int, int> v = grafo[u][i];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }

    return dist[dest];
}

int main(){
    int N, M, C, K, U, V, P;

    while(cin >> N >> M >> C >> K){
        if(!N && !M && !C && !K)    break;

        grafo.assign(N, vector<pair<int, int> >());

        for(int i = 0; i < M; ++i){
            cin >> U >> V >> P;
            grafo[U].push_back(make_pair(V, P));
            grafo[V].push_back(make_pair(U, P));
        }

        int caminho = 0;
        for(int i = C - 2; i > -1; --i){
            for(int j = 0; j < grafo[i].size(); ++j){
                if(grafo[i][j].first == i + 1){
                    P = grafo[i][j].second;
                    break;
                }
            }
            caminho += P;
            grafo[i].clear();
            grafo[i].push_back(make_pair(C - 1, caminho));
        }

        cout << Dijsktra(N, K, C - 1) << endl;
    }

    return 0;
}