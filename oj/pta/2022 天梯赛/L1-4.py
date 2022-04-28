import math

A, B = map(int, input().split())
C = A + B

result = 1
for i in range(1, C+1):
    result *= i
print(result, end='')
