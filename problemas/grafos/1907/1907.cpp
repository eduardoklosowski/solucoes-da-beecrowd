#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char grid[2000][2000];

void bfs(int i, int j){
    queue<pair<int, int> > fila;

    fila.push(make_pair(i, j));

    while(!fila.empty()){
        pair<int, int> posicao = fila.front();
        fila.pop();

        int i = posicao.first;
        int j = posicao.second;

        if(grid[i][j] == '.'){
            grid[i][j] = 'o';
            fila.push(make_pair(i - 1, j));
            fila.push(make_pair(i, j + 1));
            fila.push(make_pair(i + 1, j));
            fila.push(make_pair(i, j - 1));
        }
    }
}

int main(){
    int N, M, resposta;

    memset(grid, 'o', sizeof(grid));

    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> grid[i][j];
        }
    }

    resposta = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(grid[i][j] == '.'){
                resposta++;
                bfs(i, j);
            }
        }
    }
    cout << resposta << endl;

    return 0;
}