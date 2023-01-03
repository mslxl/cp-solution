N = int(input())


def process(text: str):
    start, end = text.split(' - ')
    return tuple(map(int, start.split(':'))), tuple(map(int, end.split(':')))


table = []
for _ in range(N):
    table.append(process(input()))

table.sort()

if table[0][0] != (0, 0, 0):
    print("%02d:%02d:%02d" % (0, 0, 0), end='')
    print(" - ", end='')
    print("%02d:%02d:%02d" % table[0][0])

for i in range(1, len(table)):
    if table[i - 1][1] != table[i][0]:
        print("%02d:%02d:%02d" % table[i - 1][1], end='')
        print(" - ", end='')
        print("%02d:%02d:%02d" % table[i][0])
if table[-1][1] != (23, 59, 59):
    print("%02d:%02d:%02d" % table[-1][1], end='')
    print(" - ", end='')
    print("%02d:%02d:%02d" % (23, 59, 59))
