input()  # Trash a line
arr = list(set(map(lambda x: int(x), input().split())))
arr.sort()
print(len(arr))
for i in arr:
    print(i, end=' ')
