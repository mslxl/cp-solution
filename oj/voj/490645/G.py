
def solve():
    _, _, q = map(int, input().split())
    s = input()
    y = input()
    for _ in range(q):
        i, l = map(int, input().split())
        x = s[i-1: i + l - 1]
        if x[::-1] == y:
          print(1)
        else:
          print(0)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        solve()
