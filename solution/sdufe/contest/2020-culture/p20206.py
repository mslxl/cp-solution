import math

global T, m, n


def idx(x, y) -> int:
    filp = x % 2 == 0
    pos = (x - 1) * n
    pos += n - y + 1 if filp else y
    return pos


if __name__ == '__main__':
    T = int(input())
    while T != 0:
        n, m = map(int, input().split())
        numC = math.ceil(m/n)
        for r in range(1, n+1):
            for c in range(1, numC+1):
                id = idx(c, r)
                if id > m:
                    break
                print(id, end=' ')
            print()
        T -= 1