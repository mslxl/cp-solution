ug, us, ub, rg, rs, rb = list(map(int, input().split()))
winColor = ug > rg or (ug == rg and us > rs) or(ug == rg and us == rs and ub > rb)
winNum = sum([ug,us,ub]) > sum([rg,rs,rb])

if winColor and winNum:
    print("both")
elif winColor:
    print("color")
elif winNum:
    print("count")
else:
    print("none")
