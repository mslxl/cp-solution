N, B = map(lambda x: int(x), input().split())
cow = []
for i in range(0, N):
    cow.append(int(input()))
cow.sort()
cow.reverse()
h = 0
n = 0
while h < B:
    h = h + cow[n]
    n = n + 1
print(n)
