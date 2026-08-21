P = [31, 42]
C = [1, 24, 90]

p_pointer = 0
c_pointer = 0

print("0   0")
while p_pointer < 2 and c_pointer < 3:
    if P[p_pointer] < C[c_pointer]:
        p_pointer += 1
    else:
        c_pointer += 1
    print(p_pointer, "", c_pointer)

while p_pointer < 2:
    p_pointer += 1
    print(p_pointer, "", c_pointer)

while c_pointer < 3:
    c_pointer += 1
    print(p_pointer, "", c_pointer)


# 3, 3 -> 90, 42, 90 > 42, print(2), add 1,