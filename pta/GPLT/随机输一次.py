LL = [int(x) for x in input().split()]
N = LL[0]
K = LL[1:]


def win(v):
    if v == 'ChuiZi':
        return 'Bu'
    elif v == 'Bu':
        return 'JianDao'
    else:
        return 'ChuiZi'
def lost(v):
    if v == 'ChuiZi':
        return 'JianDao'
    elif v == 'JianDao':
        return 'Bu'
    else:
        return 'ChuiZi'

vv = input()
idx = 0
while vv != 'End':
    idx += 1
    if idx > K[0]:
        print(lost(vv))
        K = K[1:] + [K[0]]
        idx = 0
    else:
        print(win(vv))
    vv = input()


