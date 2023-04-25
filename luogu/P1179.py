L, R = map(lambda x: int(x), input().split())
t = 0
for i in range(L, R + 1):
    while i > 0:
        if i % 10 == 2:
            t = t + 1
        i = i // 10
print(t)
