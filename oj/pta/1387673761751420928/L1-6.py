N, M = map(int, input().split())
for idx in range(0, N):
    Q = input()
    if M == 0:
        print(Q, end='')
        exit(0)
    if "qiandao" not in Q and "easy" not in Q:
        M-=1
print("Wo AK le", end='')
