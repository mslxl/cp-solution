# 日常语言劣势，#4 会 TLE
import sys

expect = int(input())
# 成本 成本预期销量
money, amount = map(lambda x: int(x), input().split())

# (售价，
data = []
cm, ca = map(lambda x: int(x), input().split())
while cm != -1 and ca != -1:
    data.append((cm,ca))
    cm, ca = map(lambda x: int(x), input().split())

ne = int(input())
t = data[-1]
while t[1] > 0:
    t = (t[0] + 1,t[1] - ne)
    if t[1] > 0:
        data.append(t)

def jud(data,offset):
    max = -1
    num = 0
    for i in data:
        val = (i[0] - money + offset) * i[1]
        if val > max:
            max = val
            num = i[0]
    return num

offset = 0
d = jud(data,offset)
if d < expect:
    while d != expect:
        offset-=1
        d = jud(data,offset) 
else:
    while d != expect:
        offset+=1
        d = jud(data,offset)

print(offset)