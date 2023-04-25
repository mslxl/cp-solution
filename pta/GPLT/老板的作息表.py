N = int(input())
time = []

def time2stamp(l: str):
    a, b = l.split('-')
    hh,mm,ss=[int(x) for x in a.strip().split(':')]
    start = hh * 60 * 60 + mm * 60 + ss
    hh, mm, ss = [int(x) for x in b.strip().split(':')]
    end = hh * 60 * 60 + mm * 60 + ss
    return start,end

def right_pad(s):
    s = str(s)
    if len(s) == 2:
        return s
    else:
        return '0' + s

def stamp2time(s):
    return f"{right_pad(int(s/60/60))}:{right_pad(int((s/60) % 60))}:{right_pad(int(s%60))}"

for _ in range(N):
    time.append(time2stamp(input()))

time.sort()
if time[0][0] != 0:
    print(f"{stamp2time(0)} - {stamp2time(time[0][0])}")

for i in range(1, len(time)):
    if time[i][0] != time[i-1][1]:
        print(f"{stamp2time(time[i-1][1])} - {stamp2time(time[i][0])}")
if time[-1][1] != 23 * 60 * 60 + 59 * 60 + 59:
    print(f"{stamp2time(time[-1][1])} - {stamp2time(23 * 60 * 60 + 59 * 60 + 59)}")

