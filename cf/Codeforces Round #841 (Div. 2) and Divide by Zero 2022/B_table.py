with open("B_table.txt", "w") as f:
    cnt = 0
    for i in range(int(1e4), int(1e9), int(1e4)):
        f.write(str(i))
        f.write('\n')
        cnt+=1
    print(cnt)

