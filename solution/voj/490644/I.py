
# int :: str a => a -> int

# map :: (a -> b) -> [a] -> [b]

def solve():
    a, b = map(int, input().split())
    num_even = 0
    num_odd = 0
    if b - a < 10:
        for i in range(a, b+1):
            if i % 3 == 0:
                num_even += 1
            else:
                num_odd += 1
    else:
        if a % 3 == 0:
            num_even += 1
        else:
            num_odd += (3 - a % 3)
        if b % 3 == 0:
            num_even += 1
            num_odd += 2
        else:
            num_odd += b % 3
    print(0 if num_odd % 2 == 0 else 1)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        solve()
