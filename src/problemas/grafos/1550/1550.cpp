#include <iostream>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

int inverte(int numero){
    int resposta = 0;

    while(numero > 0){
        resposta *= 10;
        resposta += numero % 10;
        numero /= 10;
    }

    return resposta;
}

int proximo(int numero, int acao){
    switch(acao){
        case 0: return (numero + 1);
        case 1: return inverte(numero);
    }
}

int main(){
    int T, A, B;
    set<int> conjunto;
    queue<pair<int, int> > fila;

    cin >> T;
    for(int i = 0; i < T; ++i){
        cin >> A >> B;

        while(!fila.empty()){
            fila.pop();
        }
        conjunto.clear();

        fila.push(make_pair(A, 0));

        while(!fila.empty()){
            pair<int, int> atual = fila.front();
            fila.pop();

            if(atual.first == B){
                cout << atual.second << endl;
                break;
            }

            int proximo1 = proximo(atual.first, 0);
            if(!conjunto.count(proximo1)){
                conjunto.insert(proximo1);
                fila.push(make_pair(proximo1, atual.second + 1));
            }

            int proximo2 = proximo(atual.first, 1);
            if(!conjunto.count(proximo2)){
                conjunto.insert(proximo2);
                fila.push(make_pair(proximo2, atual.second + 1));
            }
        }
    }

    return 0;
}