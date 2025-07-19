#include <iostream>
#include <queue>

using namespace std;

class No{
    public:
    int valor;
    No* esq;
    No* dir;

    No(){
        this->valor = -1;
        this->esq = NULL;
        this->dir = NULL;
    }

    No(int valor){
        this->valor = valor;
        this->esq = NULL;
        this->dir = NULL;
    }
};

No* adiciona(No* no, int valor){
    if(no == NULL){
        return new No(valor);
    }else{
        if(valor < no->valor){
            no->esq = adiciona(no->esq, valor);
        }else{
            no->dir = adiciona(no->dir, valor);
        }
        return no;
    }
}

int main(){
    No* arvore;
    int C, N, x;
    queue<No*> fila;

    cin >> C;
    for(int i = 1; i <= C; ++i){
        cin >> N;
        arvore = NULL;
        for(int j = 0; j < N; ++j){
            cin >> x;
            arvore = adiciona(arvore, x);
        }

        if(i > 1)   cout << endl;

        fila.push(arvore);
        cout << "Case " << i << ":" << endl;
        bool first = true;
        while(!fila.empty()){
            No* atual = fila.front();
            fila.pop();

            if(first)   first = false;
            else        cout << ' ';

            cout << atual->valor;
            if(atual->esq != NULL)  fila.push(atual->esq);
            if(atual->dir != NULL)  fila.push(atual->dir);
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}