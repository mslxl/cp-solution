b = [int(x) for x in input().split()]
k = int(input())
cur = [7, 7, 7, 7, 7, 7]

for i in range(k):
    for j in range(6):
        cur[j] -= 1
        if b[j] == cur[j]:
            cur[j] -= 1

ans = ""
for i in cur:
    ans += str(i) + ' '

print(ans.strip())
