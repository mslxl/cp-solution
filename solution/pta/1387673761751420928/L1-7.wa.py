input()
seq = list(map(int, input().split()))
seq.sort()
for i in range(1, len(seq)):
    if seq[0] != seq[i]:
        print("{} {}".format(seq[0], i))
        break

lst = len(seq) - 1
for i in range(1, len(seq)):
    if seq[lst] != seq[lst - i]:
        print("{} {}".format(seq[lst], i), end = '')
        break
