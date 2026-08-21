N, K = map(int, input().split())
A = list(map(int, input().split()))

if N == len(A):
    A.sort(reverse=True)

    print(A[K - 1])