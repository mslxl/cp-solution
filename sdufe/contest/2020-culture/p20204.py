input()
arr = list(map(int, input().split()))
result = [arr[0]]
idx = 1

while idx < len(arr):
    result.append(arr[idx] + result[idx-1])
    idx += 1

for item in result:
    print(item, end=' ')