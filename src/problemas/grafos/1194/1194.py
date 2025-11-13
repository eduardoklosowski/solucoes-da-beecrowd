class Arvore:
    def __init__(self, valor):
        self.valor = valor
        self.esq = None
        self.dir = None

def posfixa(arvore):
    if(arvore == None):
        return
    posfixa(arvore.esq)
    posfixa(arvore.dir)
    print(arvore.valor, end='')

testes = int(input())

for k in range(testes):
    _, prefixa, infixa = input().strip().split(' ')
    indices = {letra: posicao for posicao, letra in enumerate(infixa)}

    arvore = Arvore(prefixa[0])
    for letra in prefixa[1:]:
        no = arvore
        while no is not None:
            no_anterior = no
            if indices[letra] < indices[no.valor]:
                no = no.esq
            else:
                no = no.dir
        if indices[letra] < indices[no_anterior.valor]:
            no_anterior.esq = Arvore(letra)
        else:
            no_anterior.dir = Arvore(letra)

    posfixa(arvore)
    print('')