#include <iostream>
#include <cstring>

using namespace std;

char grid[60][60];

void contamina(int i, int j){
    grid[i][j] = 'T';

    if(grid[i - 1][j] == 'A')   contamina(i - 1, j);
    if(grid[i + 1][j] == 'A')   contamina(i + 1, j);
    if(grid[i][j - 1] == 'A')   contamina(i, j - 1);
    if(grid[i][j + 1] == 'A')   contamina(i, j + 1);
}

int main(){
    int N, M;

    while(cin >> N >> M){
        if(!N && !M)    break;

        memset(grid, 'X', sizeof(grid));

        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cin >> grid[i][j];
            }
        }

        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(grid[i][j] == 'T'){
                    contamina(i, j);
                }
            }
        }

        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}