import math

N = int(input())
# N = 27683

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

if isPrime(N) or N == 1:
    print("1")
    print(N, end='')
    exit(0)

num_start = None
num_len = 0
for i in range(2, math.ceil(math.sqrt(N))+ 1):
    if N % i == 0:
        prod = i
        if num_len == 0:
            num_len = 1
            num_start = i
        for j in range(i + 1, math.ceil(math.sqrt(N)) + 1):
            prod *= j
            if N % prod != 0:
                break
            if j - i + 1 > num_len:
                num_len = j - i + 1
                num_start = i

print(num_len)
print("*".join(map(str,range(num_start, num_start + num_len))), end = '')
