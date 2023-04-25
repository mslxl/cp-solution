N = int(input())

for i in range(N):
    wd = input()
    if wd[-1] == '?':
        if "PTA" in wd:
            print("Yes!")
        else:
            print("No.")
    else:
        print("enen")