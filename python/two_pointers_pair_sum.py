lista = [2, 9, 18, 7, 9, 7, 1, 2, 8]
x = 11

lista.sort()

print(lista)

l = 0
r = len(lista) - 1

while (lista[l] + lista[r]) != x:
    sum = lista[l] + lista[r]
    if sum > x:
        r -= 1
    elif sum < x:
        l += 1

print(lista[l], lista[r])
    

#O(N log N)
# O(N^2)

