#include <iostream>

using namespace std;

bool chega(int m[7][7], int x, int y){
    m[x][y] = 1;

    if(x == 5 && y == 5){
        return true;
    }else{
        bool retorno = false;

        if(m[x - 1][y] == 0){
            retorno = retorno || chega(m, x - 1, y);
        }
        if(m[x + 1][y] == 0){
            retorno = retorno || chega(m, x + 1, y);
        }
        if(m[x][y - 1] == 0){
            retorno = retorno || chega(m, x, y - 1);
        }
        if(m[x][y + 1] == 0){
            retorno = retorno || chega(m, x, y + 1);
        }

        return retorno;
    }
}

int main(){
    int T;
    int matriz[7][7];

    cin >> T;
    for(int k = 0; k < T; ++k){
        for(int i = 0; i < 7; ++i){
            matriz[0][i] = 1;
            matriz[i][0] = 1;
            matriz[6][i] = 1;
            matriz[i][6] = 1;
        }
        for(int i = 1; i < 6; ++i){
            for(int j = 1; j < 6; ++j){
                cin >> matriz[i][j];
            }
        }

        cout << (string) (chega(matriz, 1, 1) ? "COPS" : "ROBBERS") << endl;
    }

    return 0;
}