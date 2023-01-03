n = int(input())
d = list(map(lambda x: int(x), input().split()))
distance = 0
for i in range(1, n):
    distance = distance + max(d[i - 1], d[i])
print(distance)
