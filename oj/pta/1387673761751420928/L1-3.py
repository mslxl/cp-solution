inp = input()
global year
global day
if len(inp) == 4:
    if int(inp[:2]) < 22:
        year = "20" + inp[:2]
    else:
        year = "19" + inp[:2]
    day = inp[2:]
else:
    year = inp[:4]
    day =inp[4:]

print("{}-{}".format(year, day), end = '')


