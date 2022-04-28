from functools import reduce
import math

int(input())

num = [tuple(map(int, i.split('/'))) for i in input().split()]

def plus(fst, snd):
    fst_1, fst_2 = fst
    snd_1, snd_2 = snd
    ret = (fst_1 * snd_2 + snd_1 * fst_2, fst_2 * snd_2)
    return ret


num = reduce(plus, num)
gcd = math.gcd(num[0], num[1])
fst, snd = (num[0]//gcd, num[1]//gcd)

if fst == 0:
    print("0")
    exit(0)

if fst * snd < 0:
    print("-", end='')
    fst = abs(fst)
    snd = abs(snd)

if fst >= snd:
    print(fst // snd, end='')
    fst %= snd
    if fst != 0:
        print(' ', end='')

if fst != 0:
    print("{:.0f}/{:.0f}".format(fst, snd), end='')
