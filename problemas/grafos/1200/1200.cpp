#include <iostream>

class No{
    public:
    char valor;
    No* esq;
    No* dir;

    No(){
        this->esq = NULL;
        this->dir = NULL;
    }

    No(char valor){
        this->valor = valor;
        this->esq = NULL;
        this->dir = NULL;
    }
};

No* adicionaNo(No* arvore, char valor){
    if(arvore == NULL){
        No* novoNo = new No(valor);
        return novoNo;
    }else{
        if(valor < arvore->valor){
            arvore->esq = adicionaNo(arvore->esq, valor);
        }else{
            arvore->dir = adicionaNo(arvore->dir, valor);
        }
        return arvore;
    }
}

No* buscaNo(No* arvore, char valor){
    if(arvore == NULL){
        return NULL;
    }else{
        if(valor == arvore->valor){
            return arvore;
        }else if(valor < arvore->valor){
            return buscaNo(arvore->esq, valor);
        }else{
            return buscaNo(arvore->dir, valor);
        }
    }
}

using namespace std;

bool first;

void Infixa(No* arvore){
    if(arvore != NULL){
        Infixa(arvore->esq);
        if(first)   first = false;
        else        cout << ' ';
        cout << arvore->valor;
        Infixa(arvore->dir);
    }
}

void Prefixa(No* arvore){
    if(arvore != NULL){
        if(first)   first = false;
        else        cout << ' ';
        cout << arvore->valor;
        Prefixa(arvore->esq);
        Prefixa(arvore->dir);
    }
}

void Posfixa(No* arvore){
    if(arvore != NULL){
        Posfixa(arvore->esq);
        Posfixa(arvore->dir);
        if(first)   first = false;
        else        cout << ' ';
        cout << arvore->valor;
    }
}

int main(){
    string instrucao;
    char letra;
    No* arvore = NULL;

    while(cin >> instrucao){
        if(instrucao == "I"){
            cin >> letra;
            arvore = adicionaNo(arvore, letra);
        }else if(instrucao == "P"){
            cin >> letra;
            No* resultado = buscaNo(arvore, letra);
            if(resultado == NULL){
                cout << letra << " nao existe" << endl;
            }else{
                cout << letra << " existe" << endl;
            }
        }else if(instrucao == "INFIXA"){
            first = true;
            Infixa(arvore);
            cout << endl;
        }else if(instrucao == "PREFIXA"){
            first = true;
            Prefixa(arvore);
            cout << endl;
        }else{
            first = true;
            Posfixa(arvore);
            cout << endl;
        }
    }

    return 0;
}