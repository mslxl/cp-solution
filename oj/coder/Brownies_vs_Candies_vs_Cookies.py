def ln() -> list[int]:
    return list(map(int, input().split()))


num_stu,  bro = ln()

for _ in range(ln()[0]):
    gp = ln()[0]
    while bro <= gp:
        bro *= 2

    bro -= gp
    print("{} {}" .format(gp, bro))
