initial = list(map(int, input().split()))
N = int(input())

occupy = [[x] for x in initial]


def max_s(occ):
    for i in range(6, 0, -1):
        if i not in occ:
            return i
    return None


for ti in range(N):
    for i in range(6):
        cur_max = max_s(occupy[i])
        occupy[i].append(cur_max)
        initial[i] = cur_max

print(" ".join(map(str, initial)), end='')
