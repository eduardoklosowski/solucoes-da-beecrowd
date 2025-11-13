#include <iostream>

using namespace std;

class No{
    public:
    char valor;
    No* esq;
    No* dir;

    No(char valor){
        this->valor = valor;
        esq = NULL;
        dir = NULL;
    }
};

int prefixoIndice;

No* ConstroiArvore(string prefixo, string infixo){
    char letra = prefixo[prefixoIndice++];
    No* no = new No(letra);
    int infixoIndice = infixo.find(letra);

    string infixoEsq = infixo.substr(0, infixoIndice);
    string infixoDir = "";
    if(infixoIndice < infixo.length() - 1){
        infixoDir = infixo.substr(infixoIndice + 1);
    }
    
    if(infixoEsq.length() == 0 && infixoDir.length() == 0){
        return no;
    }

    if(infixoEsq.length() > 0){
        no->esq = ConstroiArvore(prefixo, infixoEsq);
    }
    if(infixoDir.length() > 0){
        no->dir = ConstroiArvore(prefixo, infixoDir);
    }

    return no;
}

void PosOrdem(No* no){
    if(no != NULL){
        PosOrdem(no->esq);
        PosOrdem(no->dir);
        cout << no->valor;
    }
}

int main(){
    int C, N;
    string prefixo, infixo;
    No* raiz;

    cin >> C;
    for(int i = 0; i < C; ++i){
        cin >> N >> prefixo >> infixo;
        
        prefixoIndice = 0;
        raiz = ConstroiArvore(prefixo, infixo);
        PosOrdem(raiz);
        cout << endl;
    }

    return 0;
}