def DFS(visitado, grafo, componente, u):
    visitado[u] = componente

    for i in range(len(grafo[u])):
        v = grafo[u][i]

        if (not visitado[v]):
            DFS(visitado, grafo, componente, v)


N = int(input())

for k in range(1, N + 1):
    V, E = [int(x) for x in input().strip().split(' ')]

    grafo = [[] for _ in range(V)]
    visitado = [0 for _ in range(V)]

    for _ in range(E):
        u, v = input().strip().split(' ')

        grafo[ord(u) - ord('a')].append(ord(v) - ord('a'))
        grafo[ord(v) - ord('a')].append(ord(u) - ord('a'))

    print(f'Case #{k}:')
    componentes = 0
    for u in range(V):
        if visitado[u] == 0:
            componentes += 1
            DFS(visitado, grafo, componentes, u)

            vertices = [
                chr(i + ord('a')) for i in range(V)
                if visitado[i] == componentes
            ]
            vertices.sort()
            texto_vertices = ','.join(vertices)
            print(f'{texto_vertices},')
    print(f'{componentes} connected components')
    print('')
