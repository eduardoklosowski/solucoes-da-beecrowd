direcoes = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def dentro(n, m, i, j):
    return 0 <= i < n and 0 <= j < m

def floodFill(matriz, n, m, i, j):
    matriz[i][j] = 'T'
    for x, y in direcoes:
        if dentro(n, m, i + x, j + y) and matriz[i + x][j + y] == 'A':
            floodFill(matriz, n, m, i + x, j + y)

while True:
    n, m = [int(x) for x in input().strip().split()]
    if n == 0 and m == 0:
        break

    matriz = []
    for _ in range(n):
        matriz.append([x for x in input().strip()])

    for i in range(n):
        for j in range(m):
            if matriz[i][j] == 'T':
                floodFill(matriz, n, m, i, j)

    for i in range(n):
        print(''.join(matriz[i]))
    print('')