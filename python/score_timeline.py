P = (input()).split()
C = (input()).split()

Tp = int(P[0])
Tc = int(C[0])
t = max(Tp, Tc)


def func1 (L, i):
    try:
        A = L[i]
        return (A)
    except:
        return (101)

def func2 (L, i):
    try:
        L.pop (i) # O(N log N)
        return (L)
    except:
        return (L)


Pp = 0
Pc = 0

print(Pp, " ", Pc)
for i in range(Tp + Tc): # O(n)
    p = int(func1 (P, 1))
    c = int(func1 (C, 1))
    if p > c:
        Pc += 1
        C = func2(C, 1)
    else:
        Pp += 1
        P = func2(P, 1)

    print (Pp, " ", Pc) 

    
