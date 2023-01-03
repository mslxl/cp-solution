ip = list(map(int, input().split()))

if 17 in ip and 18 in ip:
    print("both")
elif 17 in ip:
    print(17)
elif 18 in ip:
    print(18)
else:
    print("none")