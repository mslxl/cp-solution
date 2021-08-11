from functools import reduce


def readTime():
    return reduce(lambda pre, cur: pre * 60 + cur, map(lambda x: int(x), input().split(':')))


bs = readTime()
s = readTime()
k = int(input())
print((s - bs) * k)
