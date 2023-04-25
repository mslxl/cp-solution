n = int(input())
stu = list(range(1, n+1))
ai = list(map(int, input().split()))
bi = list(map(int, input().split()))

leave = []
friendNum = {}
maxFrindNum = 1

for action in range(n):
    willLeave = ai[action]-1
    leaveStu = stu[willLeave]
    del stu[willLeave]
    leave.append(leaveStu)
    if bi[action] != 0:
        for beFri in leave[-bi[action] - 1:-1]:
            if leaveStu not in friendNum:
                friendNum[leaveStu] = 1
            else:
                friendNum[leaveStu] += 1
            if maxFrindNum < friendNum[leaveStu]:
                maxFrindNum = friendNum[leaveStu]

            if beFri not in friendNum:
                friendNum[beFri] = 1
            else:
                friendNum[beFri] += 1
                if maxFrindNum < friendNum[beFri]:
                    maxFrindNum = friendNum[beFri]
for i in range(1,n+1):
    f = friendNum[i]
    isMax = "Yes" if f  == maxFrindNum else "No"
    print(str(f) + ' ' + isMax)
