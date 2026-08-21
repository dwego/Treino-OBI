n = list(input())

for i in range(4 - len(n)):
    n.insert(i, "0")

x = int("".join(sorted(n))) - sorted(n, reverse=True)

print()