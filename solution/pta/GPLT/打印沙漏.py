# -*- coding: utf-8 -*-
import sys
import math

N, c = input().split()
N = int(N)
if N < 7 :
    print("{}\n{}".format(c,N-1), end='')
    sys.exit(0)

used = 1
idx = 1
buffer = [c]

while used + (idx + 2) * 2 <= N:
    idx += 2
    used += idx * 2
    buffer = [c * idx] + buffer + [c * idx]
    
max_char = len(buffer[0])
for line in buffer:
    sp = (max_char - len(line)) // 2
    print(sp * ' ', end = '')
    print(line)

print(N - used, end='')
