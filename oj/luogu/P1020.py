missile = list(map(int, input().split()))

left = 0
length = 1
array_len = len(missile)

suit = 0
best_len = length

def is_vaild(c_left, c_len) -> int:
    for i in range(c_left + 1,c_left + c_len+ 1):
        if missile[i] >= missile[i-1]:
            return i
    return 0
        

while left + length < array_len:
    if missile[left + length] > missile[left + length - 1]:
        length+=1
    else:
        if best_len < length:
            best_len = length
        suit += 1
        left += length


