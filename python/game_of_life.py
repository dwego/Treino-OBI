deslocamentos = [(-1, 0), (1, 0), (0, -1), (0, 1), (1, 1), (-1, 1), (1, -1), (-1, -1)]
N, Q = map(int, input().split())

matriz = []
new_matriz = []
for i in range(N):
    row = input()
    lista_numeros = [int(digito) for digito in row]
    if N == len(row):
        matriz.append(lista_numeros)

for k in range(Q):
    new_matriz = [linha[:] for linha in matriz]
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            alived = 0 
            for di, dj in deslocamentos:
                    ni = i + di
                    nj = j + dj

                    if 0 <= ni < len(matriz) and 0 <= nj < len(matriz[i]):
                        if matriz[ni][nj] == 1:
                            alived += 1
            if matriz[i][j] == 0 and alived == 3:
                    new_matriz[i][j] = 1
            if matriz[i][j] == 1 and alived not in [2, 3]:
                    new_matriz[i][j] = 0
    
    matriz = new_matriz

print()
for i in matriz:
    row = ''.join(map(str, i))
    row = row.replace("0", "_")
    row = row.replace("1", "*")

    print(row)