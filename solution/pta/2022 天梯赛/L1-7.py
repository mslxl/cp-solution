N, M, Q = map(int, input().split())
safe = N * M
G = []
for i in range(M):
    row = []
    for j in range(N):
        row.append(True)
    G.append(row)

for _ in range(Q):
    T, C = map(int, input().split())
    C -= 1
    if T == 0:
        # row
        for col in range(0, M):
            if G[col][C]:
                safe -= 1
                G[col][C] = False
    else:
        # col
        for row in range(0, N):
            if G[C][row]:
                safe -= 1
                G[C][row] = False

print(str(safe), end='')
