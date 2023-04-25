import math
(n, k) = [int(i) for i in input().split()]
seq = list([int(i) for i in input().split()])
valid = 0
for i in seq:
    for j in seq:
        for x in seq:
            if (i + j + x) == k:
                valid = valid + 1
t = math.gcd(valid, n ** 3)
print(str(valid // t) + "/" + str(n ** 3 // t), end='')
