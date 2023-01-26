def check(map) -> bool:
    for x in range(len(map)):
        for y in range(len(map[x])):

            for w in range(x+1, len(map)):
                for h in range(y+1, len(map[x])):

                    if map[x][y] == map[w][y] and map[x][h] == map[w][h]:
                        return True
                    elif map[x][y] == map[x][h] and map[w][y] == map[w][h]:
                        return True
    return False


map = [[None for i in range(9)] for j in range(9)]


def zero(n, m):
    return [[0 for i in range(n)] for j in range(m)]


def is_end(map) -> bool:
    for y in map:
        for x in y:
            if x != 2:
                return False
    return True


def inc(map):
    map[0][0] += 1
    for i in range(len(map)):
        for j in range(len(map[i])):
            if map[i][j] > 2:
                map[i][j] = 0
                if j+1 == len(map[i]):
                    if i+1 != len(map):
                        map[i+1][0] += 1
                else:
                    map[i][j+1] += 1


with open("H.txt", "w") as f:
    f.write("{")
    for m in range(1, 10):
        f.write("{")
        for n in range(1, 10):
            ans = 0
            map = zero(n, m)
            print(str(len(map)) + "," + str(len(map[0])))
            if check(map):
                ans += 1
            while True:
                inc(map)
                if check(map):
                    ans += 1 
                if is_end(map):
                    break
            print(ans)
            f.write(str(ans))
            if n != 9:
                f.write(",")
        if m != 9:
            f.write(",")
        f.write("}")



