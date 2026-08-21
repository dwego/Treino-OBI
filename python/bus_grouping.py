N, T = map(int, input().split())

tempos = list(map(int, input().split()))

counter = tempos[0]
onibus = 1
for i in range(1, N):
    if abs(counter - tempos[i]) > T:
        onibus += 1
        counter = tempos[i]

print(onibus)