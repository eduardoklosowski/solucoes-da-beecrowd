#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<bool> visitado;
vector<vector<pair<int, double>>> grafo;
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> fila;

void processa(int u){
    visitado[u] = true;

    for(int i = 0; i < grafo[u].size(); ++i){
        pair<int, double> par = grafo[u][i];
        int v = par.first;
        double d = par.second;

        if(!visitado[v]){
            fila.push(pair<double, int>(d, v));
        }
    }
}

double distancia(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    int C, n, x, y;
    double resposta;
    vector<pair<double, double> > pessoas;

    cout << setprecision(2) << fixed;

    cin >> C;
    for(int k = 0; k < C; ++k){
        cin >> n;

        pessoas.assign(n, pair<int, int>());
        grafo.assign(n, vector<pair<int, double> >());
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            pessoas[i] = pair<double, double>(x/100.0, y/100.0);
        }

        for(int i = 0; i < n; ++i){
            pair<double, double> p1 = pessoas[i];
            for(int j = i + 1; j < n; ++j){
                pair<double, double> p2 = pessoas[j];

                double dist = distancia(p1.first, p1.second, p2.first, p2.second);
                grafo[i].push_back(pair<int, double>(j, dist));
                grafo[j].push_back(pair<int, double>(i, dist));
            }
        }

        visitado.assign(n, false);
        processa(0);
        resposta = 0;
        while(!fila.empty()){
            pair<double, int> frente = fila.top();
            fila.pop();

            double d = frente.first;
            int u = frente.second;

            if(!visitado[u]){
                resposta += d;
                processa(u);
            }
        }

        cout << resposta << endl;
    }
}