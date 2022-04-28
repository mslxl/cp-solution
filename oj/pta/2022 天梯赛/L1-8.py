N, K, S = map(int, input().split())
stu = []
for _ in range(N):
    GL, PAT = map(int, input().split())
    if GL >= 175:
        stu.append((GL, PAT))
stu.sort()

passed = 0

for _ in range(K):
    last_sco = 0
    tot_len = len(stu)
    i = 0
    while i < tot_len:
        if stu[i][0] > last_sco:
            passed += 1
            last_sco = stu[i][0]
            del stu[i]
            tot_len -= 1
        elif stu[i][0] == last_sco and stu[i][1] >= S:
            passed += 1
            del stu[i]
            tot_len -= 1
        else:
            i += 1

print(passed, end='')
