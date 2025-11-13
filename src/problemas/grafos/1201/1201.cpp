#include <iostream>

class No{
    public:
    int valor;
    No* esq;
    No* dir;

    No(){
        this->esq = NULL;
        this->dir = NULL;
    }

    No(int valor){
        this->valor = valor;
        this->esq = NULL;
        this->dir = NULL;
    }
};

No* adicionaNo(No* arvore, int valor){
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

No* buscaNo(No* arvore, int valor){
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

No* removeNo(No* arvore, int valor){
    if(arvore == NULL){
        return NULL;
    }
    if(valor < arvore->valor){
        arvore->esq = removeNo(arvore->esq, valor);
        return arvore;
    }else if (valor > arvore->valor){
        arvore->dir = removeNo(arvore->dir, valor);
        return arvore;
    }else{
        if(arvore->esq == NULL){
            No* direita = arvore->dir;
            free(arvore);
            return direita;
        }else if(arvore->dir == NULL){
            No* esquerda = arvore->esq;
            free(arvore);
            return esquerda;
        }else{
            No* antecessor = arvore->esq;
            while(antecessor->dir != NULL){
                antecessor = antecessor->dir;
            }
            arvore->valor = antecessor->valor;
            arvore->esq = removeNo(arvore->esq, antecessor->valor);
            return arvore;
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
    int numero;
    No* arvore = NULL;

    while(cin >> instrucao){
        if(instrucao == "I"){
            cin >> numero;
            arvore = adicionaNo(arvore, numero);
        }else if(instrucao == "P"){
            cin >> numero;
            No* resultado = buscaNo(arvore, numero);
            if(resultado == NULL){
                cout << numero << " nao existe" << endl;
            }else{
                cout << numero << " existe" << endl;
            }
        }else if(instrucao == "R"){
            cin >> numero;
            arvore = removeNo(arvore, numero);
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