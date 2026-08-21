fita = ['B', 'P', 'B', 'B', 'P', 'B', 'P', 'P', 'B', 'B']
posicao = 3
direcao = 1 # direita
contador = 0
passos = 0

while passos < 8:
    if fita[posicao] == 'P':
        contador = contador + 2
    else:
        contador = contador + 1
    
    if contador % 2 == 0:
        if fita[posicao] == 'P':
            fita[posicao] = 'B'
        else:
            fita[posicao] = 'P'

        if direcao == 1:
            direcao = 0
        else:
            direcao = 1

    if direcao == 1:
        posicao = posicao + 1
    else:
        posicao = posicao - 1

    passos = passos + 1

print(fita)
print(contador)