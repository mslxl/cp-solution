N = int(input())
fibs = [0,1,2]
if N > 2:
    for idx in range(3,N+1):
        fibs.append(fibs[idx-2] + fibs[idx-1])
print(fibs[N], end='')
