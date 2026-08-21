import math
N1, N2, N3, N4 = map(int, input().split())

mesa = 0

mesa += N4
mesa += N3

if N2 % 2 == 0:
    mesa += N2 / 2
    if N1 > N3:
        mesa += math.ceil((N1 - N3) / 4)

else:
    mesa += (N2 + 1 )/ 2
    if N1 > N3 and (N1 - N3) > 2:
        mesa += math.ceil((N1 - N3 - 2) / 4)

print(round(mesa))