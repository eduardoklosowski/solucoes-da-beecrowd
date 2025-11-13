#include <iostream>
#include <queue>
#include <set>

using namespace std;

pair<int, int> coordenada(string posicao){
    return make_pair(8 - (posicao[1] - '0'), posicao[0] - 'a');
}

bool dentro(pair<int, int> coord){
    return (coord.first > -1 && coord.first < 8 && coord.second > -1 && coord.second < 8);
}

int main(){
    vector<pair<int, int> > available_moves;
    queue<pair<pair<int, int> , int> > fila;
    set<pair<int, int> > visitado;
    pair<int, int> inicio, fim;
    string i, f;

    available_moves.push_back(make_pair(-2, -1));
    available_moves.push_back(make_pair(-2, 1));
    available_moves.push_back(make_pair(-1, 2));
    available_moves.push_back(make_pair(1, 2));
    available_moves.push_back(make_pair(2, 1));
    available_moves.push_back(make_pair(2, -1));
    available_moves.push_back(make_pair(1, -2));
    available_moves.push_back(make_pair(-1, -2));

    while(cin >> i >> f){
        inicio = coordenada(i);
        fim = coordenada(f);

        while(!fila.empty()){
            fila.pop();
        }
        visitado.clear();

        fila.push(make_pair(inicio, 0));

        while(!fila.empty()){
            pair<pair<int, int>, int> atual = fila.front();
            fila.pop();
            visitado.insert(atual.first);

            if(atual.first == fim){
                cout << "To get from " << i << " to " << f << " takes " << atual.second << " knight moves." << endl;
                break;
            }

            for(int i = 0; i < available_moves.size(); ++i){
                pair<int, int> move = available_moves[i];
                pair<int, int> proximo = make_pair(atual.first.first + move.first, atual.first.second + move.second);
                if(dentro(proximo) && !visitado.count(proximo)){
                    fila.push(make_pair(proximo, atual.second + 1));
                }
            }
        }
    }

    return 0;
}