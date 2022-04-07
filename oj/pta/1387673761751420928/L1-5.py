seq=list(map(int, input().split()))

ip = int(input())
while ip >= 0 and ip < len(seq):
    print(str(seq[ip]) + " " + ("Yes" if seq[ip] > 50 else "No"), end='')
    ip = int(input())
    if ip >= 0 and ip < len(seq):
        print()
